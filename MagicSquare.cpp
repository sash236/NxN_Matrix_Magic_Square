
/* MAGIC SQUARE - An NxN matrix containing values from 1 to N*N that are  */
/* ordered so that the sum of the rows, columns, and the major diagonals  */
/* are all equal.  There is a particular algorithm for odd integers, and  */
/* this program constructs that matrix, up to 13 rows and columns.  This   */
/* program also adds the sums of the row, columns, and major diagonals.   */

#include <iostream>	
#include <ctype.h>
#include <iomanip>
using namespace std;


class Matrix {

	public:
		void Display(int input);
		void Calculate(int input);
		int GetInput();
		void Init(int input);
		void Rmem(int input);
		void Intro();

	private:
		int **m_loc;								  /* Array holding all          */
												   /*  input*input values.       */

		int m_row;                                 /* Determines row of matrix   */
		int m_col;                                 /* Determines col of matrix   */
		int m_otherdiag;                           /* Total of one matrix diagonal*/
		int m_value;                               /* Integer between 1 and      */
												  /*  input*input               */
};

/************
* Function: Init
* Purpose: 
*		Initialize the variables
* 
* Parameters: 
*		member variables. m_row, m_col, m_input,m_otherdiag, m_loc
*
*
* Local Variables: 
*		nNumber, input: both holds the value passed on; x, int variable
*
************/
void Matrix::Init(int nNumber)
{

// Dynamic memory allocation

	int input = nNumber;
	nNumber++;


	m_loc = new int*[nNumber];

	for (int x=0; x < nNumber; x++)
		m_loc[x] = new int[nNumber ];

/*                                                                        */
/*    Initialize matrix, row, col, and otherdiag                          */
/*                                                                        */
      for (m_row = 0; m_row <= input; m_row++)    /* Initialize matrix with     */
         for (m_col = 0; m_col <= input; m_col++) /*  all zeroes.               */
            m_loc[m_row][m_col] = 0;              /* Values will reside within  */
                                            /*  rows 1 to input*input and */
                                            /*  columns 1 to input*input. */
                                            /* Row totals will reside in  */
                                            /*  m_loc[row][0], where row is */
                                            /*  the row number, while the */
                                            /*  column totals will reside */
                                            /*  in m_loc[0][col], where col */
                                            /*  is the column number.     */  
      m_row = 1;                              /* First value gets to sit on */
      m_col = input/2 + 1;                    /*  1st row, middle of matrix.*/
      m_otherdiag = 0;
}

/************
* Function: Rmem
* Purpose: 
*		Deletes dynamic memory allocation for m_loc double pointer.
* 
* Parameters: 
*		member variables. m_loc
*
* Local Variables: 
*		x: an int variable; nNumber: holds the value passed on
*
************/

void Matrix::Rmem(int nNumber)
{
	nNumber++;

		for (int x=0; x < nNumber; x++)
			delete [] m_loc[x];

		delete [] m_loc;
}


/************
* Function: GetInput
* Purpose: 
*		Getting Valid Numeric Input
* 
* Parameters: 
*
* Local Variables: 
*		nInput: holds the user entered data.
*
*
************/
int Matrix::GetInput()
{

	int nInput = 0;

	for (;;) // infinite for loop
	{
	// executed one or more times
	cout << "\nEnter a positive,"; 
	cout << " odd integer (-1 to exit program):\n";
	cin >> nInput;

	// if numbers entered, enter the block
	  if (cin.good()) { 
		if (nInput == -1) {
				cout << "You Enterted = "<< nInput << "; So exiting the program\n";
				break;
		}

/*                                                                        */                                                       
/*    Validity check for input: Must be a positive odd integer < 13.      */
/*                                                                        */

		else if (nInput <= 0)	{
			cout << "Sorry, but the integer has";
			cout << " to be positive.\n";
			}

		else if (nInput > 15)	{
			cout << "Sorry, but the integer has";
			cout << " to be less than 15.\n";
			}

		else if (nInput%2 == 0)	{
			cout << "Sorry, but the integer has to be odd.\n";
		}

		else 
			break;

	  } // end if cin.good()


	else if (!isdigit(nInput))
	cout << "Only digits are allowed!\n";

	cin.clear();   //  executed zero or more times
	cin.ignore(120, '\n'); // executed zero or more times
	} // end for loop


	return(nInput);

}

/************
* Function: Intro
* Purpose: 
*		Prints the intriductory instruction to the user.
* 
* Parameters: 
*
* Local Variables: 
*
*
************/
void Matrix::Intro()
{
/*                                                                        */
/* Print introduction of what this program is all about.                  */
/*                                                                        */

	cout << "\nMagic Squares: This program produces an NxN matrix where\n";
	cout << "N is some positive odd integer.  The matrix contains the \n";
	cout << "values 1 to N*N.  The sum of each row, each column, and \n";
	cout << "the two main diagonals are all equal.  Not only does this \n";
	cout << "program produces the matrix, it also computes the totals for\n";
	cout << "each row, column, and two main diagonals.\n";

	cout << "\nBecause of display constraints, this program can work with\n";
	cout << "values up to 13 only.\n\n";

}



/************
* Function: Calculate
* Purpose: 
*		Calcualtes the array
* 
* Parameters: 
*		member variables. m_row, m_col, m_otherdiag,m_value
*
*
* Local Variables: 
*		input: holds the value passed on
*
************/
void Matrix::Calculate(int input)
{

 /*                                                                        */
/*    Loop for every value up to input*input, and position value in matrix*/
/*                                                                        */
      for (m_value = 1; m_value <= input*input; m_value++)
      {                                     /* Loop for all values.       */
         if (m_loc[m_row][m_col] > 0)             /* If some value already      */
         {                                  /*  present, then             */
            m_row += 2;                       /*  move down 1 row of prev.  */
            if (m_row > input)                /*  If exceeds side, then     */    
               m_row -= input;                /*   go to other side.        */

            m_col--;                          /*  move left 1 column.       */
            if (m_col < 1)                    /*  If exceeds side, then     */
               m_col = input;                 /*   go to other side.        */
         }

         m_loc[m_row][m_col] = m_value;             /* Assign value to location.  */

/*                                                                        */
/*       Add to totals                                                    */ 
/*                                                                        */
         m_loc[0][m_col] += m_value;              /* Add to its column total.   */
         m_loc[m_row][0] += m_value;              /* Add to its row total.      */
         if (m_row == m_col)                    /* Add to diagonal total if   */
            m_loc[0][0] += m_value;             /*  it falls on the diagonal. */

         if (m_row+m_col == input+1)            /* Add to other diagonal if   */
            m_otherdiag += m_value;             /*  it falls on the line.     */

/*                                                                        */
/*       Determine where new row and col are                              */
/*                                                                        */
         m_row--;
         if (m_row < 1)                       /* If row exceeds side then   */
            m_row = input;                    /*  goto other side.          */
         m_col++;
         if (m_col > input)                   /* If col exceeds side then   */
            m_col = 1;                        /*  goto other side.          */
      }                                     /* End of getting all values. */
}

/************
* Function: Display
* Purpose: 
*		Displays the array on the screen
* 
* Parameters: 
*		member variables. m_row, m_col,m_otherdiag,m_value
*
*
* Local Variables: 
*		input: holds the value passed on 
*
************/
void Matrix::Display(int input)
{
/*                                                                        */
/*    Print out the matrix with its totals                                */
/*                                                                        */
      cout <<"\nThe number you selected was "<< input;
      cout <<", and the matrix is:\n\n";
      for (m_row = 1; m_row <= input; m_row++)			  /* Loop: print a row at a time*/
      {
         cout <<"     ";										 /* Create column for diag.total*/
         for (m_col = 1; m_col <= input; m_col++)
		 cout << setw(5)<< m_loc[m_row][m_col] ;					/* Print values found in a row*/
		 cout <<" = "<< setw(5)<< m_loc[m_row][0] << endl ;		/* Print total of row.        */
      }

 /*                                                                        */
/*    Print out the totals for each column, starting with diagonal total. */
/*                                                                        */
      for (m_col = 0; m_col <= input; m_col++)     /* Print line separating the  */
         cout <<"-----";						  /*  value matrix and col totals*/
		 cout << endl << setw(5)<< m_otherdiag;			/* Print out the diagonal total*/
      for (m_col = 1; m_col <= input; m_col++)
		  cout << setw(5)<< m_loc[0][m_col];				/* Print out the column totals*/
		  cout <<"   "<< setw(5) << m_loc[0][0]<<endl;	/* Print out the other diagonal*/
													     /*  total                     */
}



/************
* Function: main
* Purpose: 
*		Process the "Magic Square"
* 
* Parameters: 
*		Fuction GetInput: get the valid user input. Fuction Init: Initialize the variables. 
*		Fuction Calculate: Calcualtes the array values. Fuction Display: Prints the Matrix on the screen
*
* Local Variables: 
*		Class type UData refers to user entered data.
*
*
************/

void main()
{
	int rValue = 0;
	Matrix UData;
	UData.Intro();

	for (;;) // infinite for loop
	{
		// executed one or more times

		rValue = UData.GetInput();
		if (rValue == -1) {
			cout << "\nBye bye!\n\n";
			break;
		}

		UData.Init(rValue);
		UData.Calculate(rValue);
		UData.Display(rValue);
		UData.Rmem(rValue);

	}   /* End of for input>-1 loop */

}


