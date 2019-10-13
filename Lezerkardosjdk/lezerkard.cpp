#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <fstream>
#include<vector>
#include<stdio.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::filesystem;

std::vector<path> v;
static int counter=0;

void read_acts ( boost::filesystem::path path )
{

        if ( is_regular_file ( path ) ) {

                std::string ext ( ".java" );
                if ( !ext.compare ( boost::filesystem::extension ( path ) ) ) {
                counter++;    
				v.push_back(path); 
                   
                }

        } else if ( is_directory ( path ) )
                for ( boost::filesystem::directory_entry & entry : boost::filesystem::directory_iterator ( path ) )
                        read_acts ( entry.path());

}

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    cout << "Kevés argumentum\n";
    return 1;
  }

  path p (argv[1]);

if (is_directory(p))
     {
        cout << p << " is a directory containing:\n";
        
        for (auto&& x : directory_iterator(p))
        { 
          read_acts(x);
        }

        std::sort(v.begin(), v.end());  

        for (auto&& x : v)
          cout << "    " << x.filename() << '\n';
     }
     else
     {
     	cout<<"Nem mappát adtál meg"<<endl;
     }
     cout<<counter<<endl;
      


  return 0;
}