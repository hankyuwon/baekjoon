#include <stdio.h>
#include <stdlib.h>


int** create_matrix(int TriangleSize);
int free_matrix(int** matrix_triangle, int TriangleSize);
void print_matrix(int** matrix_triangle, int TriangleSize);
int Search_matrix(int** matrix_triangle, int** matrix_max, int TriangleSize);

int main(){

    int TriangleSize;
    scanf("%d",&TriangleSize);

    int** matrix_triangle = create_matrix(TriangleSize);
    int** matrix_max=create_matrix(TriangleSize);

    for(int i=0;i<TriangleSize;i++)
    {
        for(int j=0;j<TriangleSize;j++)
        {
            matrix_max[i][j]=0;
        }
    }

    for(int i=0;i<TriangleSize;i++)
    {
        int TriangleCount=0;
        for(int j=0;j<TriangleSize;j++)
        {
            if(TriangleCount>i)
            matrix_triangle[i][j]=0;

            else{
            scanf("%d",&matrix_triangle[i][j]);
            TriangleCount++;
            }

        }
    }

    Search_matrix(matrix_triangle, matrix_max, TriangleSize);
        
    free_matrix(matrix_triangle, TriangleSize);

    return 0;
}


int** create_matrix(int TriangleSize){
    if(TriangleSize<0||TriangleSize>500) return NULL;

    int** matrix=(int**)malloc(sizeof(int*)*TriangleSize);

    for(int i=0;i<TriangleSize;i++)
    {
        matrix[i]=(int*)malloc(sizeof(int)*TriangleSize);
    }

    if(matrix==NULL)
    {
        printf("Memory Allocation Failed\n");

        return NULL;
    }

    return matrix;
}

int free_matrix(int** matrix_triangle, int TriangleSize){
    for(int i=0;i<TriangleSize;i++)
    {
        free(matrix_triangle[i]);
    }
    free(matrix_triangle);
    return 1;
}

int Search_matrix(int** matrix_triangle,int** matrix_max, int TriangleSize){
    

    for(int i=0;i<TriangleSize;i++)
    {
        for(int j=0;j<TriangleSize;j++)
        {
            if(i==0&&j==0){
                matrix_max[i][j]=matrix_triangle[i][j];

            }
                else{
            

            if(j==0||j==i)
            {
                if(j==0)
                matrix_max[i][j]=matrix_max[i-1][j]+matrix_triangle[i][j];

                else
                matrix_max[i][j]=matrix_max[i-1][j-1]+matrix_triangle[i][j];
            }
            else if(j>i) break;
            else{
                if(matrix_max[i-1][j-1]>matrix_max[i-1][j])
                {
                    matrix_max[i][j]=matrix_max[i-1][j-1]+matrix_triangle[i][j];
                }
                else
                matrix_max[i][j]=matrix_max[i-1][j]+matrix_triangle[i][j];
            }
                }
        }
    }

    int final=0;

    for(int i=0;i<TriangleSize;i++)
    {
        if(matrix_max[TriangleSize-1][i]>final)
        final=matrix_max[TriangleSize-1][i];
    }

    printf("%d",final);

    return 1;
}

/* Debug for matrix

void print_matrix(int** matrix_triangle, int TriangleSize){
    for(int i=0;i<TriangleSize;i++)
    {
        for(int j=0;j<TriangleSize;j++)
        {
            printf("%5d",matrix_triangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

*/