#include <stdio.h>
#include <assert.h>

//https://www.codewars.com/kata/52685f7382004e774f0001f7
//
// Write a function, which takes a non-negative integer (seconds) as input and
// returns the time in a human-readable format (HH:MM:SS)
//
// HH = hours, padded to 2 digits, range: 00 - 99
// MM = minutes, padded to 2 digits, range: 00 - 59
// SS = seconds, padded to 2 digits, range: 00 - 59
//
// The maximum time never exceeds 359999 (99:59:59)

char *human_readable_time (unsigned seconds, char *time_string)
{
    int hrs = seconds / 3600;
    int mins = (seconds - hrs * 3600) / 60;
    int sec = seconds % 60;
    sprintf(time_string, "%s%d:%s%d:%s%d\0", 
        hrs / 10 == 0 ? "0" : "", hrs, 
        mins / 10 == 0 ? "0" : "", mins, 
        sec / 10 == 0 ? "0" : "", sec);

	return time_string; // return it
}

#define RES_LEN 9

int main(int argc, char* argv[]) {
    char* res = malloc(sizeof(char) * RES_LEN);
    assert(strcmp("00:00:00", human_readable_time(0, res)) == 0);
	assert(strcmp("00:00:59", human_readable_time(59, res)) == 0);
	assert(strcmp("00:01:00", human_readable_time(60, res)) == 0);
	assert(strcmp("00:01:30", human_readable_time(90, res)) == 0);
	assert(strcmp("00:59:59", human_readable_time(3599, res)) == 0);
	assert(strcmp("01:00:00", human_readable_time(3600, res)) == 0);
	assert(strcmp("12:34:56", human_readable_time(45296, res)) == 0);
	assert(strcmp("23:59:59", human_readable_time(86399, res)) == 0);
	assert(strcmp("24:00:00", human_readable_time(86400, res)) == 0);
	assert(strcmp("99:59:59", human_readable_time(359999, res)) == 0);
}