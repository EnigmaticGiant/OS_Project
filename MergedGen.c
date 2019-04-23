#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct page_table_entry{
	int mem;
	int disk;
	int dirty;
	int pad;
}page_table_entry;

page_table_entry *newPageTableEntry(){
	page_table_entry *new = malloc(sizeof(page_table_entry));
	new->mem =0;
	new->disk =0;
	new->dirty =0;
	new->pad =0;
	return new;
}

void setPageTableEntry(page_table_entry *pte){
	pte->mem = 12;
	pte->disk = 13;
	pte->dirty = 1;
	pte->pad = 6;
}

/*
page_table_entry *getPageTable(int num){
	return page_table_array[num];
}

void putPageTable(int num, page_table_entry *pte){
	page_table_array[num] = pte;
}*/

int getMem(page_table_entry *pte){
	return pte->mem;
}

int getDisk(page_table_entry *pte){
	return pte->disk;
}

int getDirty(page_table_entry *pte){
	return pte->dirty;
}

int getPad(page_table_entry *pte){
	return pte->pad;
}

void printPageStats(FILE *fp, page_table_entry *pte){
	fprintf(fp, "%d %d %d %d\n", getMem(pte), getDisk(pte), getDirty(pte), getPad(pte) );
}

void generate(int n){
		FILE *fp;
		char s[32];
		for(int i = 0; i < n; i++){
			sprintf(s, "final%d", i);
			fp = fopen(s, "w");
			if(!fp) 
				dam("file did not open");
			struct page_table_entry* page_table_array[256];
			for(int i = 0; i < 256; i++){
				page_table_array[i] = newPageTableEntry();
			}
			for(int i = 0; i < 256; i++){
				printPageStats(fp, page_table_array[i]);
			}
        	fprintf(fp,"%9i\n",0);                                  // Position in the file
	        fprintf(fp,"%9i\n",random_between(0,3));                // Priority of the file
   		    fprintf(fp,"%9i\n",random_between(10,200));             // Memory of the file
	        fprintf(fp,"%9i\n",5000);                               // Remain
	        fprintf(fp,"%9i\n",0);                                  // Start time
        	fprintf(fp,"%9i\n",0);                                  // End time
			
			for(int i=0;i<100;i++){
				fprintf(fp,"%3i\n",i);
			}

		}
}

int main()
{
	generate(10);
}
