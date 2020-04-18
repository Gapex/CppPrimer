#include <iostream>
#include <fstream>
#include <string>

struct Sales_data;

std::istream &read(std::istream &in, Sales_data &ref);
std::ostream &print(std::ostream &out, const Sales_data &ref2C);
Sales_data add(const Sales_data &lh, const Sales_data &rh);

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold;
    double revenue;
    double price;

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &rhs);

    //因为需要提供其他构造函数，因此也需要定义自己的默认构造函数
    Sales_data() = default;      //隐式inline
    Sales_data(std::istream &in) //从输入流读入，类内定义，称为隐式inline
    {
        read(in, *this);
    }
    Sales_data(std::string bookNo);
    Sales_data(std::string bookNo, unsigned units_sold, double price);
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    price = revenue / units_sold;
    return *this;
}

std::istream &read(std::istream &in, Sales_data &ref)
{
    in >> ref.bookNo >> ref.units_sold >> ref.price;
    ref.revenue = ref.units_sold * ref.price;
    return in;
}

std::ostream &print(std::ostream &out, const Sales_data &ref2C)
{
    out << ref2C.bookNo << " "
        << ref2C.units_sold << ' '
        << ref2C.revenue << ' '
        << ref2C.price;
}

Sales_data add(const Sales_data &lh, const Sales_data &rh)
{
    Sales_data ans = lh;
    ans.combine(rh);
    return ans;
}

using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::istream;
using std::ostream;
using std::ofstream;

istream &auto_src(istream &src1, int argc=1, istream &src2=std::cin){
    if(argc > 1) return src1;
    else return src2;
}

ostream &auto_dst(ostream &src1, int argc=1, ostream &src2=cout){
    if(argc > 1) return src1;
    else return src2;
}

int main(int argc, char *argv[])
{
    ifstream ifile;
    ofstream ofile;
    if(argc > 1){
        if(argc != 3){
            std::cerr << "需要同时指定输出文件" << endl;
            return -1;
        }
        ifile.open(argv[1]);
        ofile.open(argv[2], ostream::app);
    }
    istream &input_stream = auto_src(ifile, argc);
    ostream &output_stream = auto_dst(ofile, argc);
    Sales_data total(input_stream);
    if (input_stream)
    {
        Sales_data trans(input_stream);
        while (input_stream)
        {
            if (trans.isbn() == total.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(output_stream, total) << endl;
                total = trans;
            }
            trans = Sales_data(input_stream);
        }
        print(output_stream, total) << endl;
    }
    if(ifile){
        ifile.close();
    }
    if(ofile){
        ofile.close();
    }
    return 0;
}