//
//  main.cpp
//  CSVparse
//
//  Created by Hank on 11/26/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVRow
{
public:
    std::string const& operator[](std::size_t index) const
    {
        return m_data[index];
    }
    std::size_t size() const
    {
        return m_data.size();
    }
    void readNextRow(std::istream& str)
    {
        std::string         line;
        std::getline(str,line);
        
        std::stringstream   lineStream(line);
        std::string         cell;
        
        m_data.clear();
        while(std::getline(lineStream,cell,','))
        {
            m_data.push_back(cell);
        }
    }
private:
    std::vector<std::string>    m_data;
};

std::istream& operator>>(std::istream& str,CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

int main()
{
    std::ifstream file("/Users/admin107/Downloads/educator.csv");
    std::ofstream f("/Users/admin107/Downloads/edu.html");
    CSVRow row;
    file >> row;
    for (int i=0;i<row.size();i++){
        f<<row[i]<<"\n";
    }
    return 0;
}