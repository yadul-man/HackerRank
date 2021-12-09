/*
We live in a big country. This country has  towns in it. Each town has some post offices in which packages are stored and transferred.

Post offices have different inner structure. Specifically, each of them has some limitations on the packages it can store - their weight should be between  and  inclusively, where  and  are fixed for each office.

Packages are stored in some order in the office queue. That means, that they are processed using this order when sending and receiving.

Sometimes two post offices, even in different towns, may organize the following transaction: the first one sends all its packages to the second one. The second one accepts the packages that satisfy the weight condition for the second office and rejects all other ones. These rejected packages return to the first office back and are stored in the same order they were stored before they were sent. The accepted packages move to the tail of the second office's queue in the same order they were stored in the first office.

You should process several queries in your program. You'll be provided with structures ,  and . in order to complete this task, you should fill the following functions:

 - given the town , print all packages in this town. They should be printed as follows:

Town_name:
    0:
        id_0
        id_1
        ...
    1:
        id_2
        id_3
        ...
    ...
where ,  etc are the numbers of post offices and , ... are the ids of packages from the th post office in the order of its queue, ,  are from the st one etc. There should be one '\t' symbol before post office numbers and two '\t' symbols before the ids.

 - given the towns  and  and post office indices  and , manage the transaction described above between the post office # in town  and the post office # in town .

 - given all towns, find the one with the most number of packages in all post offices altogether. If there are several of them, find the first one from the collection .

 - given all towns and a string , find the town with the name . It's guaranteed that the town exists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
    printf("%s:\n", t.name);

    for(int i = 0; i < t.offices_count; i++){
        printf("\t%d:\n", i);
        for(int j = 0; j < t.offices[i].packages_count; j++){
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int nPackages_toTransffer = source->offices[source_office_index].packages_count;
    int minWeight = target->offices[target_office_index].min_weight;
    int maxWeight = target->offices[target_office_index].max_weight;

    for(int i = 0; i < nPackages_toTransffer; i++){
        if(source->offices[source_office_index].packages[i].weight <= maxWeight && source->offices[source_office_index].packages[i].weight >= minWeight){

            //This var also sums plus one package in the target office
            int nPackages_target = ++target->offices[target_office_index].packages_count;
            source->offices[source_office_index].packages_count--;

            target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages, sizeof(package) * nPackages_target);

            target->offices[target_office_index].packages[nPackages_target - 1] = source->offices[source_office_index].packages[i];

            package fill;
            
            fill.id = "XXX";

            source->offices[source_office_index].packages[i] = fill;

        }

    }

    for(int i = 0; i < nPackages_toTransffer; i++){
        if(strcmp(source->offices[source_office_index].packages[i].id, "XXX") == 0){
            for(int j = i; j < nPackages_toTransffer - 1; j++){
                source->offices[source_office_index].packages[j] = source->offices[source_office_index].packages[j + 1];
            }
        }
    }

    source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages, sizeof(package) * source->offices[source_office_index].packages_count);

}

town town_with_most_packages(town* towns, int towns_count){
    int max = 0, mcity;


    for(int i = 0; i < towns_count; i++){
        int sum = 0;

        for(int j = 0; j < towns[i].offices_count; j++){
            sum += towns[i].offices[j].packages_count;
        }

        if(sum > max){
            max = sum;
            mcity = i;
        }
    }

    return towns[mcity];

}

town find_town(town* towns, int towns_count, char* name) {
    int i;
    for(i = 0; i < towns_count; i++){
        if(strcmp(towns[i].name, name) == 0)
            break;
    }

    return towns[i];
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
        case 1:
            scanf("%s", town_name);
            town t = find_town(towns, towns_count, town_name);
            print_all_packages(t);
            break;
        case 2:
            scanf("%s", town_name);
            town source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);
            scanf("%s", town_name);
            town target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);
            send_all_acceptable_packages(&source, source_index, &target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}
