/*
Bryan Wood
Lib.h

infile, outfile, outpsfile, entry, Avg,

*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>

/*-------------------------------------------------------
Opens reguired files and reports if the file cannot be found
Receives: infile, outfile, outpsfile
Returns: infile, outfile, outpsfile
---------------------------------------------------------*/
void openfiles (ifstream &infile, ofstream &outfile1, 
				ofstream &outfile2);

/*-------------------------------------------------------
closes all files referenced by this program
Receives: infile, outfile, outpsfile
---------------------------------------------------------*/
void closefiles (ifstream &infile, ofstream &outfile1, 
				 ofstream &outfile2);

/*-------------------------------------------------------
Reads input from the input file, manipulates data (finds 
	average, highest average, and counts the number of 
	entries), and outputs the results to both output files.
Receives: infile, outfile, outpsfile, entry, Avg
Returns: infile, outfile, outpsfile, entry, Avg
---------------------------------------------------------*/
void process (istream &infile, ostream &outfile1, ostream &outfile2, 
			  int &entry, double &Avg);

/*-------------------------------------------------------
finds the high and low average then computes the total of 
	the top 4 out of 5 scores
Receives: score1, score2, score3, score4, score5
returns: upavg
---------------------------------------------------------*/
double upperavg (double score1, double score2, double score3, 
			double score4, double score5);

/*-------------------------------------------------------
prints a header in the output files specified for the data 
	that is in the file.
Receives: outfile, outpsfile
---------------------------------------------------------*/
void headers (ostream &outfile1, ostream &outfile2);

/*-------------------------------------------------------
creates the report line that contains the student number 
	and average score then prints the results into an 
	outputfile called: p8.out
Receives: outfile, student, Avg
---------------------------------------------------------*/
void report (ostream &outfile1, long student, double &Avg);

/*-------------------------------------------------------
creates a sumary of task performed in the process function and
	prints results into an output file called: p8.out.
Receives: outfile, entry, Avg, low, hi
---------------------------------------------------------*/
void summary (ostream &outfile1, int entry, double Avg, 
			  double low, double hi);

/*-------------------------------------------------------
creates a bar chart using the '~' as a space holder and the 
Receives: outpsfile, Avg, student
---------------------------------------------------------*/
void barchart (ostream &outfile1, double Avg, long student);

/*-------------------------------------------------------
creates a sumary of task performed in the process function and
	prints results into a second output file called: ps8.out.
Receives: outpsfile, entry, Avg, low, hi
---------------------------------------------------------*/
void barchartsummary (ostream &outfile2, int entry, 
					  double low, double hi);

/*-------------------------------------------------------
prints finished statement to screen
Receives: entry, Avg
Returns: nothing
---------------------------------------------------------*/
void scSummary (int entry, double Avg);
