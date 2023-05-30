#include<stdio.h>

int main()
{
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    float miss_ratio, hit_ratio;
    int page_hits = 0;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter the reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
        
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;
    
    for(i = 1; i < n; i++)
    {
        c1 = 0;
        
        for(j = 0; j < f; j++)
        {
            if(p[i] != q[j])
                c1++;
        }
        
        if(c1 == f)
        {
            c++;
            
            if(k < f)
            {
                q[k] = p[i];
                k++;
                
                for(j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                    
                printf("\n");
            }
            else
            {
                for(r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    
                    for(j = i - 1; j < n; j--)
                    {
                        if(q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                
                for(r = 0; r < f; r++)
                    b[r] = c2[r];
                    
                for(r = 0; r < f; r++)
                {
                    for(j = r; j < f; j++)
                    {
                        if(b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                
                for(r = 0; r < f; r++)
                {
                    if(c2[r] == b[0])
                        q[r] = p[i];
                    
                    printf("\t%d", q[r]);
                }
                
                printf("\n");
            }
        }
        else
        {
            page_hits++;
        }
    }
    
    miss_ratio = (float)c / n;
    hit_ratio = (float)page_hits / n;
    
    printf("\nThe number of page faults is %d\n", c);
    printf("The number of page hits is %d\n", page_hits);
    printf("The miss ratio is %.2f\n", miss_ratio);
    printf("The hit ratio is %.2f\n", hit_ratio);
    
    return 0;
}
