#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define N 7
using namespace std;

int sum=0;
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *p, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(*(p + j) > *(p + j + 1)){
                swap(*(p + j), *(p + j + 1));
            }
        }
    }
}
void match(int *a,int *u,int set,FILE *str)
{
	int special=0,normal = 0;
	printf("Set %d you match: ",set+1);
	fprintf(str,"Set %d you match: ",set+1);
	for(int i=0;i<6;i++)
	{
		for (int j=0;j<7;j++)
		{
			if (j==6 && *(u+i) == *(a+j))
			{
				special=1;
				printf("%d(bonus) ",*(u+i));
				fprintf(str,"%d(bonus) ",*(u+i));
			}
			else if (*(u+i) == *(a+j))
			{
				normal++;
				printf("%d ",*(u+i));
				fprintf(str,"%d ",*(u+i));
			}
		}
	}
	if (normal == 5 && special==1) 
	{
		printf(" You won the first prize!$5000\n");
		fprintf(str," You won the first prize!$5000\n");
		sum +=5000;
	}
	else if (normal == 5 && special ==0)
	{
		printf(" You won the second prize!$4000\n");
		fprintf(str," You won the second prize!$4000\n");
		sum += 4000;
	}
	else if (normal == 4 && special==1)
	{
		printf(" You won the third prize!$3000\n");
		fprintf(str," You won the third prize!$3000\n");
		sum += 3000;
	} 
	else if (normal == 4 && special==0)
	{
		printf(" You won the fourth prize!$2000\n");
		fprintf(str," You won the fourth prize!$2000\n");
		sum += 2000;
	}
	else if (normal == 3 && special==1)
	{
		printf(" You won the fifth prize!$1000\n");
		fprintf(str," You won the fifth prize!$1000\n");
		sum += 1000;
	}
	else if (normal == 3)
	{
		printf(" You won the sixth prize!$100\n");
		fprintf(str," You won the sixth prize!$100\n");
		sum += 100;
	}
	else {
		printf(" You miss any prize!\n");
		fprintf(str," You miss any prize!\n");
	}
}

int main(){
    srand(time(NULL));
    int arr[N][7];
    
    //check if adjacent or repeat and fill array
    for(int i = 0; i < N; i++){
        
        for(int j = 0; j < N; j++){
            arr[i][j] = rand() % 25 + 1;
            for(int k = 0; k < j; k++)
			{
                if(abs(arr[i][j] - arr[i][k]) == 1 || (arr[i][j] == arr[i][k]))
				{
                    j--;
                    break;
                }
			}
			
        }
    }
    for(int j = 0; j < N; j++) sort(arr[j],6);
    
	//print origin
    cout << "-------lottery-------\n";
    for(int i = 0; i < N; i++){
        cout << i + 1 << " -> ";
        

        for(int j = 0; j < N; j++){
        	if(j==6) cout << "*" ;
            if(arr[i][j] < 10)  cout << " ";
            
            cout << arr[i][j] << " ";
        }

        cout << "\n";
    }
    
	
    //user's numbers
	int user[N][6];
	FILE *stream = fopen("data.txt","w");
	for(int i = 0; i < N; i++){
        
        for(int j = 0; j < 6; j++){
            user[i][j] = rand() % 25 + 1;
            for(int k = 0; k < j; k++)
			{
                if(abs(user[i][j] - user[i][k]) == 1 || (user[i][j] == user[i][k]))
				{
                    j--;
                    break;
                }
			}
        }
		for(int j = 0; j < N; j++) sort(user[j],6);
		
        printf("Your numbers, Set %d: ",i+1);
        fprintf(stream,"Your numbers, Set %d: ",i+1);
        
        for (int j=0;j<6;j++)
        {
        	printf("%d,",user[i][j]);
        	fprintf(stream,"%d,",user[i][j]);
		}
		printf("\n");
		fprintf(stream,"\n");
    }
    
    for (int i=0;i<N;i++)
    {
    	match(arr[i],user[i],i,stream);
	}
	printf("\nYour total reward : $%d\n",sum);
	fprintf(stream,"\nYour total reward : $%d\n",sum);
    
    
    return 0;
    } 
