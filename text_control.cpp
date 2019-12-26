#include "text_control.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

text_control::text_control(){}

text_control::~text_control(){}

int text_control::create_file(string file_name)
{
    fstream file;

    fileName=(file_name+".txt");

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string

    file.open( cFileName, std::ios::out);
    if(file.good()==true)
    {
        file.close();
    }
}

int text_control::open_file(string file_name)
{
    fstream file;

    fileName=(file_name+".txt");

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string

    file.open( cFileName, std::ios::in);
    if(file.good()==true)
    {
        file.close();
    }
}

int text_control::print()
{
    std::fstream file;

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string


    file.open( cFileName, std::ios::in | std::ios::out );

    if( file.good() == true )
    {
        cout<<all_text;
        file.close();
    }

}

int text_control::load_all()
{
    std::fstream file;

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string

    file.open( cFileName, std::ios::in | std::ios::out );

    if( file.good() == true )
    {
        for( ; file.eof() == false; )
        {
            string line;

            getline( file, line );

            if( line == "" )
            {
                continue;
            }
            all_text += line;
            all_text += '\n';

        }
        file.close();
    }
}

int text_control::load_line(int line_number)
{

    std::fstream file;

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string

                //cFileName
    file.open( cFileName, std::ios::in | std::ios::out | std::ios::app);

   if( file.good() == true )
    {
        for( int x=0; x<line_number; x++ )
        {
            string line;


            getline( file, line );

            if( line == "\n" && x!=0 )
            {
                continue;
            }

            //file>>a>>b>>c>>d;

            all_text=line;
            file.ignore(0, '\n');
            if(file.eof()==true)
            {
                return 0;
            }
        }
        file.close();
    }







}

int text_control::save(string data)
{
    std::fstream file;

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string

                //cFileName
    file.open( cFileName, std::ios::in | std::ios::out | std::ios::app);
    if( file.good() == true )
    {
        file << data;
        file.close();
    }
}

int text_control::clear()
{
    std::fstream file;

    char *cFileName = &fileName[0];//konwersja na *char => funkcja open nie przyjmuje string

                //cFileName
    file.open( cFileName, std::ios::in | std::ios::out | std::ios::trunc);
    if( file.good() == true )
    {
        file.close();
    }
}

int text_control::convert(string var)
{
    stringstream change(var);
    change>>a;
    return a;
}

