#include<stdio.h>

int main()
{
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    float hit_ratio, fault_ratio;
    int page_hits = 0;

    printf("\nENTER THE NUMBER OF PAGES: ");
    scanf("%d", &n);
    printf("ENTER THE PAGE NUMBER:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);

    for(i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;

    printf("\tRef String\tPage Frames\n");
    for(i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;

        for(k = 0; k < no; k++)
        {
            if(frame[k] == a[i])
            {
                avail = 1;
                page_hits++;
                break;
            }
        }

        if(avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;

            for(k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }

    hit_ratio = (float)page_hits / n;
    fault_ratio = 1.0 - hit_ratio;

    printf("Page Faults: %d\n", count);
    printf("Page Hits: %d\n", page_hits);
    printf("Fault Ratio: %.2f\n", fault_ratio);
    printf("hit ratio:%.2f\n",hit_ratio);

    return 0;
}
