#include<stdio.h>

void print(int frameno, int frame[])
{
    int j;
    for(j = 0; j < frameno; j++)
        printf("%d\t", frame[j]);
    printf("\n");
}

int main()
{
    int i, j, k, n, page[50], frameno, frame[10], move = 0, flag, count = 0, count1[10] = {0},
        repindex, leastcount;
    float rate;
    int page_hits = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &frameno);

    for(i = 0; i < frameno; i++)
        frame[i] = -1;

    printf("Page reference string\tFrames\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t\t", page[i]);
        flag = 0;

        for(j = 0; j < frameno; j++)
        {
            if(page[i] == frame[j])
            {
                flag = 1;
                count1[j]++;
                printf("No replacement\n");
                page_hits++;
                break;
            }
        }

        if(flag == 0 && count < frameno)
        {
            frame[move] = page[i];
            count1[move] = 1;
            move = (move + 1) % frameno;
            count++;
            print(frameno, frame);
        }
        else if(flag == 0)
        {
            repindex = 0;
            leastcount = count1[0];

            for(j = 1; j < frameno; j++)
            {
                if(count1[j] < leastcount)
                {
                    repindex = j;
                    leastcount = count1[j];
                }
            }

            frame[repindex] = page[i];
            count1[repindex] = 1;
            count++;
            print(frameno, frame);
        }
    }

    rate = (float)count / (float)n;
    float hit_ratio = (float)page_hits / n;

    printf("Number of page faults: %d\n", count);
    printf("Number of page hits: %d\n", page_hits);
    printf("Fault rate: %f\n", rate);
    printf("Hit ratio: %f\n", hit_ratio);

    return 0;
}
