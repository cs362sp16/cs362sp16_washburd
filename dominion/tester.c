#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE *fp, *gp;
	char buff[1024];
	fp = fopen ("unittestresults.out", "w");
	
	gp = popen("unittest1", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	gp = popen("unittest2", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	gp = popen("unittest3", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	gp = popen("unittest4", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	gp = popen("cardtest2", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	gp = popen("cardtest3", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	gp = popen("cardtest4", "r");
	while(fgets(buff, sizeof(buff), gp)!=NULL){
		fprintf(fp, "%s", buff);
    }
	pclose(gp);
	
	
	return 0;
}
