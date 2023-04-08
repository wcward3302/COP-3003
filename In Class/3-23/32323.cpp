#include <iostream>
#include <vector>

int main(){

    struct job_listing { 

        int ID;

        std::string name;
        std::string disc;
        long salary;

    } ;

    //job_listing job_offer{001, "test", "testing testing testing", 100000 }; // initial values, can be x.x'd later to change

    std::vector <job_listing> job_offer;


    while(true){
        std::string temp_string;
        long temp_long;

        std::cout << "Enter _____ " ;
        std::getline (std::cin>>std::ws, temp_string);

        if(temp_string == "exit"){ // its exit and get out or its not and we continue
            break;
        }
        
        // this will create and new struct for every loop (?)
        job_offer.push_back(job_listing{0, temp_string, "", 0});

        

    }


    for (auto i : job_offer){

        std::cout << i.ID << "\t";
        std::cout << i.name << "\t";
        std::cout << i.disc << "\t";
        std::cout << i.salary << "\t";

    }
    

}