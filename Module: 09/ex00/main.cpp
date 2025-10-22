/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:04:04 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/31 23:04:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool init(myMap &Database, int ac, char **av)
{
    size_t pos;
    str line, date, value;

    // Check argument
        if (ac != 2) return err_msg(BAD_ARG);

    // Check if files can open
        File INPUT(av[1]);
        File DATABASE("data.csv");
        if (!INPUT.is_open()) return err_msg(RD_FILE_FAIL, av[1]);
        if (!DATABASE.is_open()) return err_msg(RD_FILE_FAIL, "data.csv");

    // Extract data from database and put inside map container
        while(std::getline(DATABASE, line))
        {
            pos = line.find(',');
            if (pos == str::npos) return err_msg(BAD_FORMAT, "Database");
            
            date = trim(line.substr(0, pos));
            value = trim(line.substr(pos + 1));
            
            if (isDate(date) && isValue(value))
                Database[date] = strtod(value.c_str(), NULL);
        }

    DATABASE.close();
    INPUT.close();
    return true;
}

int main(int ac, char **av)
{   
    size_t pos;
    str line, date, value;
    myMap Database;
    myMap::iterator i;
    double price;

    if (!init(Database, ac, av)) return EXIT_FAILURE;
    File INPUT(av[1]);

    while(std::getline(INPUT, line))
    {
        // Check input format is correct
            pos = line.find('|');
            if (pos == str::npos) 
            {err_msg(BAD_INPUT, line); continue;}
            
            date = trim(line.substr(0, pos));
            value = trim(line.substr(pos + 1));

            if (date == "date" && value == "value") continue;

            if (!isDate(date))   {err_msg(BAD_INPUT, date); continue;}
            if (!isValue(value)) {err_msg(BAD_INPUT, value); continue;}

        // Check if date available in database
            for (i=Database.begin(); i != Database.end(); i++)
            {
                if (i->first == date)
                    break;
                else if (i->first > date)
                {--i; break;}
            }
            if (i == Database.end())
            {err_msg(NO_DATA, date); continue;}

        // Ensure coin is within 0 to 1000
            price = strtod(value.c_str(), NULL);
            if (price < 0.0)   {err_msg(BELOW_MIN); continue;}
            if (price > 1000.0){err_msg(ABOVE_MAX); continue;}
        
        //Print out
        std::cout << date << " => " << price << " = " << i->second * price << std::endl;
    }
    INPUT.close();
}