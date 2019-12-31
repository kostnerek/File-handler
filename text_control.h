#ifndef TEXT_CONTROL_H
#define TEXT_CONTROL_H
#include <fstream>
#include <string>
using namespace std;


class text_control
{
    public:
        string fileName;
        string data;
        string all_text;
        string a;



        text_control();
        text_control(string file_name);
        ~text_control();


        int create_file(string file_name); 
        int open_file(string file_name);  
        int save(string data);  
        int print(); 
        int clear(); 
        int convert(string var);
        int load_line(int line);

        int load_all(); 
        






};

#endif // TEXT_CONTROL_H
