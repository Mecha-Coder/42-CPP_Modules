/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  logic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:51:53 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 22:51:53 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int run(std::string filename, std::string s1, std::string s2)
{
    int status = 0;
    std::string line;
    size_t pos;

    std::ifstream infile(filename.c_str());
    std::ofstream outfile((filename + ".replace").c_str());
    
    if (!infile.is_open() && ++status)
        std::cerr << ERR2 << filename << std::endl;
        
    else if (!outfile.is_open() && ++status)
        std::cerr << ERR3 << std::endl;

    if (!status)
    {
        while(std::getline(infile, line))
        {
            pos = line.find(s1);
            if (pos != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
            }
            outfile << line << std::endl;
        }
    }

    infile.close();
    outfile.close();
    return (status);
}