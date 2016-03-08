/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isValid(int d, int m, int y);
int isLeap(int y);
int isOlder(char *dob1, char *dob2) {
	int i, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;

	//checking for valid date format
	for (i = 0; *(dob1 + i) != '\0' || *(dob2 + i) != '\0'; i++){
		if (i != 2 && i != 5){
			if ((dob1[i] >= '0'&&dob1[i] <= '9') && (dob2[i] >= '0'&&dob2[i] <= '9'))
				continue;
			else return -1;
		}
		else {
			if (dob1[i] != '-' || dob2[i] != '-')
				return -1;
		}
	}//for

	//getting date
	for (i = 0; dob1[i] != '-'&&dob2[i] != '-'; i++){
		d1 = (d1 * 10) + (dob1[i] - '0');
		d2 = (d2 * 10) + (dob2[i] - '0');
	}
	if (d1 > 31 || d2 > 31) return -1;

	//getting month
	for (i = 3; *(dob1 + i) != '-' && *(dob2 + i) != '-'; i++){
		m1 = (m1 * 10) + (dob1[i] - '0');
		m2 = (m2 * 10) + (dob2[i] - '0');
	}
	if (m1 > 12 || m2 > 12) return -1;

	//getting years
	for (i = 6; *(dob1 + i) != '\0'&&*(dob2 + i) != '\0'; i++){
		y1 = (y1 * 10) + (dob1[i] - '0');
		y2 = (y2 * 10) + (dob2[i] - '0');
	}

	//checking isolder
	if (isValid(d1, m1, y1) && isValid(d2, m2, y2)){
		if (y1<y2) return 1;
		else if (y2<y1) return 2;//if y1 not less than y2 and y2 is not less than y1 
		                         //means y1==y2 so check for months
		else if (m1<m2) return 1;
		else if (m2<m1) return 2;//if m1 not less than m2 and m2 is not less than m1 
		                         //means m1==m2 so check for days
		else if (d1<d2) return 1;
		else if (d2<d1) return 2;//if d1 not less than d2 and d2 is not less than d1 
		                         //means dob1==dob2 so two dates are equal

		else return 0;
	}
	return -1;
}
int isValid(int d, int m, int y){
	if (m == 2 && isLeap(y) && d<30) return 1;
	else if (m == 2 && !isLeap(y) && d<29) return 1;
	else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d < 32) return 1;
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d < 31) return 1;
	return 0;
}
int isLeap(int y){
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
		return 1;
	return 0;
}