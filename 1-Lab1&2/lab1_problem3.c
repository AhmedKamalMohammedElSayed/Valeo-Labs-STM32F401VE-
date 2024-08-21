#include <stdio.h>

int main()
{
    int totalTime, hours, minutes, seconds;

    printf("Enter the total time elapsed in seconds: ");
    scanf("%d", &totalTime);

    hours = totalTime / 3600;           // 1 hour = 3600 seconds
    minutes = (totalTime % 3600) / 60;  // 1 minute = 60 seconds
    seconds = (totalTime % 3600) % 60;

    printf("Time elapsed: %d:%d:%d\n", hours, minutes, seconds);

    return 0;
}
