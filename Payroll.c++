#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//functions
float Pay_Commiss();
float Bi_Weekly_Payroll();
float Compute_Bi_Weekly_Wage (float,int);
float Compute_Tax_Rate(float);
void reporting(string,string,float);
//declare input

int main()
{
              //print personal info
			  ifstream inFile;
              inFile.open("assn142_a.txt");
              if(inFile)
                        cout << "Input file opened okay" << endl;
              else
                            cout << "Input file did NOT open!!" << endl;
              cout << endl;
              //print header
              cout << ''''''''\t'''''''' << "PAYROLL REPORT" << endl;
              cout << "Date - 03/29/17” << endl << endl;
              cout << "EMPLOYEE NAME" << ''''''''\t\t'''''''' << "Total COMPENSATION" << endl << endl;
              //declare variables
              string First_Name;
              string Last_Name;
              char Employee_Type;
              float Total_Comp;
              float Total= 0.0;
              //calculate compensation until the end of the file
              do
              {
                           //get data
                            inFile >> First_Name >> Last_Name >> Employee_Type;
                            //decide wwhat type of workers
                            if(Employee_Type == ''''''''C'''''''')
                                          Total_Comp= Pay_Commiss() + 500.0;
                            else if(Employee_Type == ''''''''H'''''''')
                                         Total_Comp= Bi_Weekly_Payroll();
                            //print data for each worker
                            reporting(First_Name,Last_Name,Total_Comp);
                            Total= Total + Total_Comp;
              }while(inFile);
             //print Total compensation
              cout << "Total" << ''''''''\t'''''''' << ''''''''\t'''''''' << ''''''''\t'''''''' << Total << endl;
              //return to OS
              return 0;
}
float Pay_Commiss()
{              
              //declare variables
              float Sale_Value;
              float Commission;
              int Num_Sales;
              float Total_Sales= 0;
              inFile >> Num_Sales;
              for(int x=0; x < Num_Sales; x++)
              {
                            inFile >> Sale_Value;
                            Total_Sales = Total_Sales + Sale_Value;
              }
              if(Total_Sales > 5000.0)
                           Commission= Total_Sales * 0.45;
              else
                            Commission= Total_Sales * 0.65;
              return Commission;
}
float Bi_Weekly_Payroll()
{
              //declare variables
              float Pay_Rate;
              int Hours_Worked;
              float Tax_Rate;
              float Wages;
              float total_earnings;
              //read data
              inFile >> Pay_Rate >> Hours_Worked;
              Tax_Rate= Compute_Tax_Rate(Pay_Rate);
              Wages= Compute_Bi_Weekly_Wage (Pay_Rate,Hours_Worked);
              total_earnings= Wages * Tax_Rate;
              //return Total earnings for hourly workers
              return total_earnings;              
}
float Compute_Tax_Rate(float Pay_Rate)
{
              float Tax_Rate;
              if(Pay_Rate <= 20.0)
                            Tax_Rate= 0.15;
              else if(Pay_Rate > 20.0)
                            Tax_Rate= 0.25;
              return Tax_Rate;
}
float Compute_Bi_Weekly_Wage (float Pay_Rate, int Hours_Worked)
{
              int Hours;
              int Overtime_hrs;
              if(Hours_Worked > 80)
              {
                            Overtime_hrs= Hours_Worked - 80;
                            Hours= 80;
              }
              else if(Hours_Worked <= 80)
              {
                            Overtime_hrs= 0;
                            Hours= Hours_Worked;
              }
              float Bi_Weekly_Wage = (Pay_Rate * float(Hours))+ (float(Overtime_hrs) * (1.5 * Pay_Rate));
              //return Wages
              return Bi_Weekly_Wage;
}
//print report for each worker
void reporting(string first_name,string last_name,float Total_Comp)
{
              cout << first_name << " " << last_name << ''''''''\t''''''''<<''''''''\t'''''''';
              cout << setprecision(2) << "$" << Total_Comp << endl;
}