#include "arithmometer.h"
#include "tool.cpp"

int main()
{
    srand((unsigned)time(NULL));
    printf("\n\n   Hello,Welcame to use WHY's calculate training\n   Please input the number of problem : ");
    int problemNum;scanf("%d",&problemNum);
    printf("\n   OK,we will creative %d promblems,and please input the range you want : \n   left : ",problemNum);
    int left;scanf("%d",&left);
    printf("  right : ");
    int right;scanf("%d",&right);
    vector<char> VEC;
    VEC.push_back('+');VEC.push_back('-');
    if(create(problemNum , &VEC , left , right , 2 , 3)) printf("\n  OK,creative successfully,you can check title and answer in Exercises.txt and Ansewrs.txt\n");
    else printf("  Error,creative failed");
    system("pause");
}

bool create(int problemNum , vector<char> *operation , int left , int right , int minNum , int maxNum)//creative formula
{
    FILE *que , *ans;
    if((que = fopen("Exercises.txt","w+")) == NULL)
    {
        printf("  Open file %s ERROR!","Exercises.txt");
        return false;
    }
    if((ans = fopen("Ansewrs.txt","w+")) == NULL)
    {
        printf("  Open file %s ERROR!","Ansewrs.txt");
        return false;
    }
    
    int count = 1;
    while(problemNum)
    {
        int num = randomNum(minNum , maxNum);
        int *arr = (int*)malloc(sizeof(int) * num);
        char *brr = (char*)malloc(sizeof(char) * (num - 1));
        for(int i = 0 ; i < num ; i++) arr[i] = randomNum(left , right);
        for(int i = 0 ; i < num - 1 ; i++) brr[i] = (*operation)[randomNum(0 , (*operation).size() - 1)];

        int *ANSWER;
        if(checkFormula(left , right , arr , brr , ANSWER , num - 1) && checkRepeat(num , arr , brr))
        {
            fprintf(que,"%d.%s\n",count,array_to_string(arr , brr , num - 1).c_str());
            fprintf(ans,"%d.%d\n",count,*ANSWER);
            problemNum--;count++;
        }
    }
    fclose(que);
    fclose(ans);
    clearRepeat();
    return true;
}