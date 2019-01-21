#include <iostream>

#include <cstdio>

#include <vector>

#include <algorithm>

#include <cstring>

const int MAX = 140;

using namespace std;





struct ranK{

    char registration_number[17];

    int local_score,location_number,local_rank,final_rank;

};



typedef struct ranK Rank;



void location_merge(vector<Rank> &a,vector<Rank> &b)

{

    vector<Rank>::iterator it = a.begin();

    while(it != a.end()){

        b.push_back(*it);

        it++;

    }

}



bool cmp(Rank a,Rank b){

    if(a.local_score != b.local_score) return a.local_score > b.local_score;

    else return strcmp(a.registration_number,b.registration_number) < 0;

}



int main()

{

    int case_number,candidate_number;

    vector<Rank> input[MAX];

    scanf("%d",&case_number);



    for(int i = 1;i <= case_number;i++){

        input[i].reserve(MAX);

        scanf("%d",&candidate_number);

        for(int j = 1;j <= candidate_number;j++){

            Rank temp;

            scanf("%s%d",temp.registration_number,&temp.local_score);

            temp.location_number = i;

            input[i].push_back(temp);

        }

    }



    for(int i = 1;i <= case_number;i++)

        sort(input[i].begin(),input[i].end(),cmp);



    for(int i = 1;i <= case_number;i++){

        int local_rank_number = 1;

        input[i][0].local_rank = local_rank_number;

        for(int j = 1;j < input[i].size();j++){

            local_rank_number++;

            if(input[i][j].local_score != input[i][j-1].local_score){

                input[i][j].local_rank = local_rank_number;

            }else{

                input[i][j].local_rank = input[i][j-1].local_rank;

            }

        }

    }



    if(case_number > 1){

        for(int i = 1;i < case_number;i++){

            location_merge(input[i],input[i+1]);

        }

    }



    for(int i = 1;i <= case_number;i++)

        vector<Rank>(input[i]).swap(input[i]);





    sort(input[case_number].begin(),input[case_number].end(),cmp);



    printf("%d\n",input[case_number].size());

    int final_rank_number = 1;

    input[case_number][0].final_rank = final_rank_number;

    int j = 0;

    printf("%s %d %d %d\n",input[case_number][j].registration_number,input[case_number][j].final_rank,input[case_number][j].location_number,input[case_number][j].local_rank);

    for(j = 1;j < input[case_number].size();j++){

        final_rank_number++;

        if(input[case_number][j].local_score != input[case_number][j-1].local_score){

            input[case_number][j].final_rank = final_rank_number;

        }else{

            input[case_number][j].final_rank = input[case_number][j-1].final_rank;

        }

        printf("%s %d %d %d\n",input[case_number][j].registration_number,input[case_number][j].final_rank,input[case_number][j].location_number,input[case_number][j].local_rank);

    }



//        input[i].clear();



    return 0;

}


