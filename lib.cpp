/*
Bryan Wood
Lib.cpp

infile, outfile, outpsfile, entry, Avg
student, Total, score1, score2,
score3, score4, score5, upavg,
hi, low, I,	x = 0, y

*/

#include "lib.h"

/*-------------------------------------------------------
Opens reguired files and reports if the file cannot be found
Receives: infile, outfile, outpsfile
Returns: infile, outfile, outpsfile
---------------------------------------------------------*/
void openfiles (ifstream &infile, ofstream &outfile1, 
				ofstream &outfile2)
{
	infile.open ("p8.dat", ios::nocreate);
	if (infile.fail())
	{
		cout << "Failed to open input file a:p8.dat" << endl;
		exit (-1);
	}

	outfile1.open ("p8.out");
	if (outfile1.fail())
	{
		cout << "Failed to open outputfiles a:p8.out" << endl;
		exit (-1);
	}

	outfile2.open ("ps8.out");
	if (outfile2.fail())
	{
		cout << "Failed to open outputfiles a:ps8.out" << endl;
		exit (-1);
	}
}//end sub

/*-------------------------------------------------------
closes all files referenced by this program
Receives: infile, outfile, outpsfile
---------------------------------------------------------*/
void closefiles (ifstream &infile, ofstream &outfile1, 
				 ofstream &outfile2)
{
	infile.close();

	outfile1.close();
	
	outfile2.close();
}//end sub

/*-------------------------------------------------------
Reads input from the input file, manipulates data (finds 
	average, highest average, and counts the number of 
	entries), and outputs the results to both output files.
Receives: infile, outfile, outpsfile, entry, Avg
Returns: infile, outfile, outpsfile, entry, Avg
---------------------------------------------------------*/
void process (istream &infile, ostream &outfile1, ostream &outfile2, 
			  int &entry, double &Avg)
{
	long
		student;

	double
		Total, score1, score2, score3, score4, 
		score5, upavg, hi, low, I;
	
	entry = 0;
	hi = 0;
	low = 100000; //question is there another way to do this
	I = 0;

	while (!infile.eof())
	{
		entry++;
		infile >> student >> score1 >> score2 >> score3 
		       >> score4 >> score5;
		
		upavg = upperavg (score1, score2, score3, score4, score5);

		if (upavg > hi)
		{
			hi = upavg;
		}
		else if (upavg < low)
		{
			low = upavg;
		}

		Total = upavg;
		Avg = Total / 4;

		report (outfile1, student, Avg);
		barchart (outfile2, Avg, student);
	}
		summary (outfile1, entry, Avg, low, hi);
		barchartsummary (outfile2, entry, low, hi);
}//end sub

/*-------------------------------------------------------
finds the high and low average then computes the total of 
	the top 4 out of 5 scores
Receives: score1, score2, score3, score4, score5
returns: upavg
---------------------------------------------------------*/
double upperavg (double score1, double score2, double score3, 
			double score4, double score5)
{
	double Hi, Low, upavg;
	Hi = Low = score1;

	if (Hi < score2)
	{
		Hi = score2;
	}
	else if (Low > score2)
	{
		Low = score2;
	}
	if (Hi < score3)
	{
		Hi = score3;
	}
	else if (Low > score3)
	{
		Low = score3;
	}
	if (Hi < score4)
	{
		Hi=Low;
	}
	else if (Low > score4)
	{
		Low = score4;
	}
	if (Hi < score5)
	{
		Hi=Low;
	}
	else if (Low > score5)
	{
		Low = score5;
	}
	upavg = (score1 + score2 + score3 + score4 + score5) - Low;
	return upavg;
}//end sub
/*-------------------------------------------------------
prints a header in the output files specified for the data 
	that is in the file.
Receives: outfile, outpsfile
---------------------------------------------------------*/
void headers (ostream &outfile1, ostream &outfile2)
{
	outfile1 << setw(10) << "Score" << setw(12) << "Student"
		     << endl << endl;

	outfile2 << "  Student" << setw(28) << "Bar Chart" 
		     << setw(28) << "Average" << endl << endl; 
}//end sub

/*-------------------------------------------------------
creates the report line that contains the student number 
	and average score then prints the results into an 
	outputfile called: p8.out
Receives: outfile, student, Avg
---------------------------------------------------------*/
void report (ostream &outfile1, long student, double &Avg)
{
	outfile1 << setprecision (2) 
		     << setiosflags (ios::showpoint | ios:: fixed)
	         << setw(12) << student << setw(9) << Avg <<endl;
}//end sub

/*-------------------------------------------------------
creates a sumary of task performed in the process function and
	prints results into an output file called: p8.out.
Receives: outfile, entry, Avg, low, hi
---------------------------------------------------------*/
void summary (ostream &outfile1, int entry, double Avg, 
			  double low, double hi)
{
	outfile1 << endl;

	outfile1 << entry << " Records processed." << endl
		     << "Hi average found: " << setprecision (2) 
		    
		 	 << setiosflags (ios::showpoint | ios::fixed)
		     << hi / 4 << endl << "Low average found: " 
		    
			 << setprecision (2) 
		     << setiosflags (ios::showpoint | ios::fixed)
			 << low / 4 << endl;
}//end sub

/*-------------------------------------------------------
creates a bar chart using the '~' as a space holder and the 
Receives: outpsfile, Avg, student
---------------------------------------------------------*/
void barchart (ostream &outfile2, double Avg, long student)
{
	int
		x = 0, y;
	
	y = Avg;
	outfile2 << setprecision (2) 
			 << setiosflags (ios::showpoint | ios:: fixed)
			 << student << " ";

	while (x != (y/2))
	{
		outfile2  << "~";
		x++;
	}
	outfile2 << " " << Avg << endl;
}//end sub

/*-------------------------------------------------------
creates a sumary of task performed in the process function and
	prints results into a second output file called: ps8.out.
Receives: outpsfile, entry, Avg, low, hi
---------------------------------------------------------*/
void barchartsummary (ostream &outfile2, int entry, 
					  double low, double hi)
{
	outfile2 << endl << "Legend: " << "Each ~ is 2 points" 
		     << endl << endl << entry << " Records processed." 
			  
			 << endl << "Hi average found: " << setprecision (2) 
		     << setiosflags (ios::showpoint | ios::fixed)
		      
			 << hi / 4 << endl << "Low average found: " 
			 << setprecision (2) 
		      
			 << setiosflags (ios::showpoint | ios::fixed)
			 << low / 4 << endl;
			  
}//end sub

/*-------------------------------------------------------
Prints finished statement to screen
Receives: entry, Avg
---------------------------------------------------------*/
void scSummary (int entry, double Avg)
{
	cout << entry << " students processed."<< endl << endl
		 <<"The files a:p8.out and a:ps8.out" << endl 
		 << "have been created." << endl;
} //end sub