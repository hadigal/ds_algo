#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class DataBag {

public:
    static const size_t cDefaultCapacity = 1;

    DataBag(unsigned capacity = cDefaultCapacity)
    : m_cur(0)
    {}

    ~DataBag() {}

    void insert(unsigned val)
    {
        m_values[m_cur] = val;
        m_cur++;
    }

    void remove()
    {
        m_cur--;
        m_values[m_cur] = 0;
    }

    unsigned get(size_t i)
    {
        return m_values[i];
    }

    size_t size()
    {
        return m_cur;
    }

    unsigned m_values[cDefaultCapacity];
    unsigned m_cur;
};

class MaxDataBag {

public:
    MaxDataBag(unsigned capacity) {}
    ~MaxDataBag() {}

    void insert(unsigned val)
    {
        unsigned lastMax = m_max.get(m_max.size());
        unsigned maxVal = fmax(lastMax, val);
        m_raw.insert(val);
        m_max.insert(maxVal);
    }

    void remove()
    {
        m_raw.remove();
        m_max.remove();
    }

    void dump()
    {
        FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
        if (m_raw.size() > 0) {
            for (size_t i = 0; i < m_raw.size() - 1; i++) {
                fprintf(fptr, "[%i,%i],", m_raw.get(i), m_max.get(i));
            }
            fprintf(fptr, "[%i,%i]", m_raw.get(m_raw.size() - 1), m_max.get(m_max.size() - 1));
        }
        fclose(fptr);
    }

    DataBag m_raw;
    DataBag m_max;
};

static_assert(sizeof(DataBag::m_values) <= sizeof(unsigned*));

int main() {
    string value;
    getline(cin, value);

    unsigned inputSize = stoi(ltrim(rtrim(value)));
    MaxDataBag bugFreeBag(inputSize);

    for (unsigned i = 0; i < inputSize; i++) {
        string tempVal;
        getline(cin, tempVal);

        int val = stoi(ltrim(rtrim(tempVal)));

        if (val >= 0) {
            bugFreeBag.insert(val);
        } else {
            bugFreeBag.remove();
        }
    }

    bugFreeBag.dump();
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
