//√Created by Mehedi Hasan Rifat
//√MIT LICENCE included
//√Credit
#include <stdio.h>

int getTheFirstDayOfTheYear(int year) {
    int day = ((year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7);

    return day;
}

int main() {
    FILE *fp = fopen("Calendar2021.txt", "w");

    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year;

    printf("Enter the year: ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    printf("\n\n******************** Welcome to %d ********************", year);
    fprintf(fp, "******************** Welcome to %d ********************", year);

    int i, j, weekDay, spaceCounter;

    weekDay = getTheFirstDayOfTheYear(year);

    for (i = 0; i < 12; i++) {
        printf("\n\n\n.................... %s ....................\n\n", month[i]);
        printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
        fprintf(fp, "\n\n\n.................... %s ....................\n\n", month[i]);
        fprintf(fp, "   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

        for (spaceCounter = 1; spaceCounter <= weekDay; spaceCounter++) {
            printf("      ");
            fprintf(fp, "      ");
        }

        for (j = 1; j <= daysInMonth[i]; j++) {
            printf("%6d", j);
            fprintf(fp, "%6d", j);
            weekDay++;
            if (weekDay > 6) {
                weekDay = 0;
                printf("\n");
                fprintf(fp, "\n");
            }
        }

    }
    printf("\n\nCreated by Mehedi Hasan Rifat\n");
    fprintf(fp, "\n\nCreated by Mehedi Hasan Rifat");

    fclose(fp);

    return 0;
}
