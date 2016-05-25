
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char other[256];
	char seed[512], s[512];
	//int seed;
	
	printf("Other directory's address: ../../cs362sp16_");		//Say student id here
	scanf("%s", other);
	
	printf("Seed: ");
	scanf("%s", seed);
	//sprintf(a, "%d", seed);
	
	system("make tester");
	strcpy(s, "testdominion ");
	strncat(s, seed, 512);
	strcat(s, " > test.tmp");
	system(s);
	
	strcpy(s, "cp randomtester.c ../../cs362sp16_");
	strncat(s, other, 256);
	strcat(s, "/dominion/randomtester.c");
	system(s);
	
	strcpy(s, "cp Makefile ../../cs362sp16_");
	strncat(s, other, 256);
	strcat(s, "/dominion/Makefile");
	system(s);
	
	strcpy(s, "cd ../../cs362sp16_");
	strncat(s, other, 256);
	strcat(s, "/dominion; make tester; testdominion ");
	strncat(s, seed, 512);
	strcat(s, " > ../../cs362sp16_washburd/dominion/test2.tmp");
	system(s);
	
	//		foulgerd	edwardrh
	
	system("diff test.tmp test2.tmp > test.diff");
	
	FILE *fp;
	fp = fopen("test.diff", "r");
	fseek(fp, 0, SEEK_END);
	if(ftell(fp) == 0){
		printf("TEST PASSED\n");
	}
	else{
		printf("TEST FAILED\n");
	}
	fclose(fp);
	
	//printf("%s\n", other);
	
}

