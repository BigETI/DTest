/*
 *            DTest functions 1.1
 *       (c) Copyright 2006-2007 by DracoBlue
 *
 * @version   : 1.2
 * @author    : DracoBlue (http://dracoblue.com)
 * @date      : 24th April 2006
 * @update    : 3rd June 2007
 *
 * This file is provided as is (no warranties).
 *
 */

#if defined _dtest_included
  #endinput
#endif
#define _dtest_included
const dtestMaximalStringSize = 255;

/* Mainpart-Sections */
stock dt_mainstart(const title[]) {
	printf("");
	printf(" _____________________________________________________________________________");
	printf(" :                                                                   \\ DTEST |");
	printf(" '                                                                    `------�");
	printf("    Testing: %s",title);

	new hour,minute,second,year,month,day;
	gettime(hour, minute, second);
	getdate(year, month, day);
	new month2[dtestMaximalStringSize];
	month2[0]=0;
	if (month==1) dt_setstring(month2,"Jan");
	if (month==2) dt_setstring(month2,"Feb");
	if (month==3) dt_setstring(month2,"Mar");
	if (month==4) dt_setstring(month2,"Apr");
	if (month==5) dt_setstring(month2,"May");
	if (month==6) dt_setstring(month2,"Jun");
	if (month==7) dt_setstring(month2,"Jul");
	if (month==8) dt_setstring(month2,"Aug");
	if (month==9) dt_setstring(month2,"Sep");
	if (month==10) dt_setstring(month2,"Oct");
	if (month==11) dt_setstring(month2,"Nov");
	if (month==12) dt_setstring(month2,"Dec");
	printf("     (%d:%d:%d, %d. %s %d)",hour,minute,second,day,month2,year);
	printf("");
}

stock dt_mainend() {
	printf("                                                                         ");
	printf("  __                                                                         .");
	printf(" |__\\________________________________________________________________________:");
	printf("");
}

/* Sub-Sections */
stock dt_start(const title[]) {
	printf("      <%s>",title);
}
stock dt_end(const title[]) {
#pragma unused title
	printf("      ");
}

/* Print results */
stock dt_ok(const what[]) {
	printf("       [OK] %s",what);
}

stock dt_no(const what[]) {
	printf("       [--] %s",what);
}


/* This function is used for workin string handling */
stock dt_setstring(dest[], const source[]) {
	new count = strlen(source);
	new i=0;
	for (i=0;i<count;i++) {
		dest[i]=source[i];
	}
	dest[count]=0;
}


/* Boolean stuff */
stock dt_Is(what, const descr[]) {
	new tmp[dtestMaximalStringSize];
	dt_setstring(tmp,descr);
	if (what) {
		strcat(tmp," true == true",dtestMaximalStringSize);
		dt_ok(tmp);
	} else {
		strcat(tmp," true <> false",dtestMaximalStringSize);
		dt_no(tmp);
	}
}

stock dt_IsNot(what, const descr[]) {
	new tmp[dtestMaximalStringSize];
	dt_setstring(tmp,descr);
	if (!what) {
		strcat(tmp," false == false",dtestMaximalStringSize);
		dt_ok(tmp);
	} else {
		strcat(tmp," false <> true",dtestMaximalStringSize);
		dt_no(tmp);
	}
}

/* String stuff */
stock dt_SSame(const what[], const what2[], const descr[]) {
	new tmp[dtestMaximalStringSize];
	dt_setstring(tmp,descr);
	strcat(tmp," ",dtestMaximalStringSize);
	strcat(tmp,what,dtestMaximalStringSize);
	if ((strcmp(what,what2,false)==0)&&(strlen(what)==strlen(what2))) {
		strcat(tmp," == ",dtestMaximalStringSize);
	} else {
		strcat(tmp," <> ",dtestMaximalStringSize);
	}
	strcat(tmp,what2,dtestMaximalStringSize);

	if ((strcmp(what,what2,false)==0)&&(strlen(what)==strlen(what2))) {
		dt_ok(tmp);
	} else {
		dt_no(tmp);
	}
}

stock dt_SSameNot(const what[], const what2[], const descr[]) {
	new tmp[dtestMaximalStringSize];
	dt_setstring(tmp,descr);
	strcat(tmp," ",dtestMaximalStringSize);
	strcat(tmp,what,dtestMaximalStringSize);
	if ((strcmp(what,what2,false)==0)&&(strlen(what)==strlen(what2))) {
		strcat(tmp," == ",dtestMaximalStringSize);
	} else {
		strcat(tmp," <> ",dtestMaximalStringSize);
	}
	strcat(tmp,what2,dtestMaximalStringSize);

	if ((strcmp(what,what2,false)==0)&&(strlen(what)==strlen(what2))) {
		dt_no(tmp);
	} else {
		dt_ok(tmp);
	}
}

/* Value stuff */
stock dt_Same(what,what2, const descr[]) {
	new tmp[dtestMaximalStringSize];
	new tmp2[dtestMaximalStringSize];
	dt_setstring(tmp,descr);
	strcat(tmp," ",dtestMaximalStringSize);
	valstr(tmp2,what);
	strcat(tmp,tmp2,dtestMaximalStringSize);
	if (what==what2) {
		strcat(tmp," == ",dtestMaximalStringSize);
	} else {
		strcat(tmp," <> ",dtestMaximalStringSize);
	}
	valstr(tmp2,what2);
	strcat(tmp,tmp2,dtestMaximalStringSize);

	if (what==what2) {
		dt_ok(tmp);
	} else {
		dt_no(tmp);
	}
}

stock dt_SameNot(what,what2, const descr[]) {
	new tmp[dtestMaximalStringSize];
	new tmp2[dtestMaximalStringSize];

	dt_setstring(tmp,descr);
	strcat(tmp," ",dtestMaximalStringSize);
	valstr(tmp2,what);
	strcat(tmp,tmp2,dtestMaximalStringSize);
	if (what!=what2) {
		strcat(tmp," == ",dtestMaximalStringSize);
	} else {
		strcat(tmp," <> ",dtestMaximalStringSize);
	}
	valstr(tmp2,what2);
	strcat(tmp,tmp2,dtestMaximalStringSize);

	if (what==what2) {
		dt_no(tmp);
	} else {
		dt_ok(tmp);
	}
}
