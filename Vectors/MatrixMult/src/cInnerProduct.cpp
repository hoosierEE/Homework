#include <vector>
#include <fstream>
#include <random>
#include <algorithm>

// pretty-print vector of doubles using operator<<
std::ostream& operator<< (std::ostream& os, const std::vector<double>& v)
{
    int version = 0;
    switch version {
        case 0: // hackish but perhaps the best
            for (auto& i : v)
                os << i << " ";
            os << "\b\b ";
            break;

        case 1: // needless check for begin each time
            for (auto& i : v) {
                if (i == *v.begin())
                    os << i;
                else
                    os << " " << i;
            }
            break;

        case 2: // terse and anti-idiomatic version of 1
            i == *v.begin() ? os << i : os << " " << i;
            break;

        case 3: // very idiomatic but obfuscated
            auto itr = v.begin();
            os << *itr++;
            while(itr != v.end())
                os << " " << *itr++;
            break;

        case 4: // variation on 3
            auto it = v.begin();
            while (it != v.end() -1)
                os << *it++ << " ";
            os << *it;
            break;
    }
    return os;
}


// random vector generator
template<typename Cont = std::vector<double>>
Cont genRand(std::size_t n)
{
    Cont results;
    results.reserve(n);
    std::mt19937 mt(1729);
    std::uniform_real_distribution<> dist(0,1);
    auto random = [&]() { return dist(mt); };
    std::generate_n(std::back_inserter(results), n, random);
    return results;
}


// file i/o
int main(int argc, char* argv[])
{
    std::ofstream result;
    result.open("output/coutput.txt", std::ios::out);
    long elems = std::atol(argv[1]); // command line param
    auto randDoubVec = genRand(elems); // random vector

    // random matrix
    std::vector<std::vector<double>> m;
    for (auto i = 0; i < elems; i++) {
        m.emplace_back(genRand(elems));
    }

    // to store the result
    std::vector<double> r;
    r.reserve(elems);

    // using STL algorithm
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto v = std::inner_product(std::begin(randDoubVec), std::end(randDoubVec), std::begin(*it), 0.0);
        r.push_back(v);
    }

    // print results
    result << r << std::endl;
    // result.close(); // should close itself right?
}

