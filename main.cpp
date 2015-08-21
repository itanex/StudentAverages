/*
Bryan Wood
main.cpp

This program uses input from a file and manipulates it into 
an average and then finds the highest and lowest of the averages.
After it is done finding the info about the input it creates two files
to display the data that was created.

infile, outfile, outpsfile, entry, Avg

*/

#include "lib.h"

void main (void)
{
	ifstream 
		infile;
	ofstream 
		outfile1,
		outfile2;

	int entry;
	double Avg;

	//opens files to be used
	openfiles (infile, outfile1, outfile2); 
	
	// creates headers in files created
	headers (outfile1, outfile2); 
	
	//processes the data from the input file
	process (infile, outfile1, outfile2, entry, Avg); 
	
	//prints a summary to the screen 
	scSummary (entry, Avg);

	//closes the files used by this program
	closefiles (infile, outfile1, outfile2);
}//end