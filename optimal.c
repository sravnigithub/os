#include<stdio.h>

int main()
{
    int n, pg[30], fr[10];
    int count[10], i, j, k, fault, f, flag, temp, current, c, dist, max, m, cnt, p, x;
    int page_hits = 0;
    int page_faults = 0;
    float hit_ratio, fault_ratio;

    fault = 0;
    dist = 0;
    k = 0;

    printf("Enter the total number of pages: ");
    scanf("%d", &n);
    printf("Enter the page sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pg[i]);
    printf("Enter frame size: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        count[i] = 0;
        fr[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        flag = 0;
        temp = pg[i];

        for(j = 0; j < f; j++)
        {
            if(temp == fr[j])
            {
                flag = 1;
                page_hits++;
                break;
            }
        }

        if((flag == 0) && (k < f))
        {
            page_faults++;
            fr[k] = temp;
            k++;
        }
        else if((flag == 0) && (k == f))
        {
            page_faults++;

            for(cnt = 0; cnt < f; cnt++)
            {
                current = fr[cnt];

                for(c = i; c < n; c++)
                {
                    if(current != pg[c])
                        count[cnt]++;
                    else
                        break;
                }
            }

            max = 0;

            for(m = 0; m < f; m++)
            {
                if(count[m] > max)
                {
                    max = count[m];
                    p = m;
                }
            }

            fr[p] = temp;
        }

        printf("\nPage %d\tFrame: ", pg[i]);
        for(x = 0; x < f; x++)
            printf("%d\t", fr[x]);
    }

    hit_ratio = (float)page_hits / n;
    fault_ratio = (float)page_faults / n;

    printf("\nTotal number of page faults: %d\n", page_faults);
    printf("Total number of page hits: %d\n", page_hits);
    printf("Page Fault Ratio: %.2f\n", fault_ratio);
    printf("Hit Ratio: %.2f\n", hit_ratio);

    return 0;
}
