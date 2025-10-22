/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:45 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 14:03:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool err_msg(Error code)
{
    CERR << RED "Error: " RESET;
    switch (code) 
    {
        case BAD_ARG: CERR << "Invalid argument. Expected => ./PmergeMe 3 5 9 7 4\n"; break;
        case NOT_NUM: CERR << "Invalid number found\n"; break;
        case NUM_OUT_RNG: CERR << "Number out of range (0 - INT_MAX)\n"; break;
    }
    return false;
}

void process_time(clock_t start, clock_t end, size_t size)
{
    double time;
    
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    COUT << "\nSorting time for " << size << " elements is = " << time << " µs\n";
}

bool isNumber(const char *s)
{
    size_t size = strlen(s);
    size_t i = 0;
    
    if (s[0] == '-' || s[0] == '+') 
        i++;
    if ((size - i) < 1 || (size - i) > 10)
        return false;
    while (s[i] != '\0')
    {
        if (!isdigit(s[i++])) 
            return false;
    }
    return true;
}

void getInsertSeq(Vector &seq, int len)
{
    int a = 1, b = 1, now;

    if (len < 2) return seq.push_back(0);

    seq.push_back(1);
    seq.push_back(0);

    while (b <= len)
    {
        now = b + 2 * a;
        for (int j = now; j > b; j--)
        {
            if (j < len)
                seq.push_back(j);
        }
        a = b;
        b = now;
    }
}

//=================================================================================

void v_pairSort(Vector &main, VecPair &pair, int &unpair)
{
    Vector::iterator i, a, b;

    if (main.size() % 2)
    {
        unpair = main.back();
        main.pop_back();
    }
    for (i = main.begin(); i != main.end();)
    {
        a = i++; 
        b = i++;
        
        if (*a > *b) pair.push_back(std::make_pair(*a, *b));
        else         pair.push_back(std::make_pair(*b, *a));
    }
}

void v_mergeSortPair(VecPair &pair)
{
    if (pair.size() <= 1) return;

    VecPair::iterator mid, l, r;
    mid = pair.begin() +  pair.size() / 2;

    VecPair left(pair.begin(), mid);
    VecPair right(mid, pair.end());

    v_mergeSortPair(left);
    v_mergeSortPair(right);

    pair.clear();
    l = left.begin();
    r = right.begin();

    while (l != left.end() && r != right.end())
    {
        if (l->first < r->first) pair.push_back(*l++);
        else                     pair.push_back(*r++);
    }
    pair.insert(pair.end(), l, left.end());
    pair.insert(pair.end(), r, right.end());
}

void v_splitPair(Vector &main, Vector &insert, VecPair &pair)
{
    VecPair::iterator i = pair.begin();

    main.clear();
    while (i != pair.end())
    {
        main.push_back(i->first);
        insert.push_back(i->second);
        i++;
    }
}

typename Vector::iterator v_binarySearch(Vector &main, int target)
{
    typename Vector::iterator  mid, begin, end;
    begin = main.begin();
    end = main.end();
    
    while (begin < end)
    {
        mid = begin + (end - begin) / 2;
        
        if (*mid < target)  begin = ++mid;
        else                end = mid;
    }
    return mid;
}

void v_binaryInsertionSort(Vector &main, Vector &insert, Vector &seq, int &unpair)
{
    Vector::iterator it_main;

    for (Vector::iterator it_seq = seq.begin() ; it_seq != seq.end(); it_seq++)
    {
        it_main = v_binarySearch(main, insert[*it_seq]);
        main.insert(it_main, insert[*it_seq]);
    }
    if (unpair >= 0)
    {
        it_main = v_binarySearch(main, unpair);
        main.insert(it_main,  unpair);
    }
}

void Ford_John_Sort(Vector &main)
{
    clock_t start, init_t, pair_t, merge_t, split_t, seq_t, insert_t;
    if (main.size() < 2) return ;
    
    start = clock();
    int unpair = -1;
    Vector insert;
    VecPair pair;
    Vector seq;
    init_t = clock();

    v_pairSort(main, pair, unpair); 
    pair_t = clock();

    v_mergeSortPair(pair);
    merge_t = clock();

    v_splitPair(main, insert, pair);
    split_t = clock();

    getInsertSeq(seq, static_cast<int>(insert.size()));
    seq_t = clock();

    v_binaryInsertionSort(main, insert, seq, unpair);
    insert_t = clock();

    COUT << "\nInit time      : " << static_cast<double>(init_t - start) / CLOCKS_PER_SEC * 1e6 << "\n"; 
    COUT << "Pair sort time : " << static_cast<double>(pair_t - init_t) / CLOCKS_PER_SEC * 1e6 << "\n"; 
    COUT << "Merge sort time: " << static_cast<double>(merge_t - pair_t) / CLOCKS_PER_SEC * 1e6 << "\n"; 
    COUT << "Split time     : " << static_cast<double>(split_t - merge_t) / CLOCKS_PER_SEC * 1e6 << "\n";
    COUT << "Get seq time   : " << static_cast<double>(seq_t - split_t) / CLOCKS_PER_SEC * 1e6 << "\n";
    COUT << "Search & Insert: " << static_cast<double>(insert_t - seq_t) / CLOCKS_PER_SEC * 1e6 << "\n\n"; 
}

//=================================================================================

void q_pairSort(Deque &main, DeqPair &pair, int &unpair)
{
    Deque::iterator i, a, b;

    if (main.size() % 2)
    {
        unpair = main.back();
        main.pop_back();
    }
    for (i = main.begin(); i != main.end();)
    {
        a = i++; 
        b = i++;
        
        if (*a > *b) pair.push_back(std::make_pair(*a, *b));
        else         pair.push_back(std::make_pair(*b, *a));
    }
}

void q_mergeSortPair(DeqPair &pair)
{
    if (pair.size() <= 1) return;

    DeqPair::iterator mid, l, r;
    mid = pair.begin() +  pair.size() / 2;

    DeqPair left(pair.begin(), mid);
    DeqPair right(mid, pair.end());

    q_mergeSortPair(left);
    q_mergeSortPair(right);

    pair.clear();
    l = left.begin();
    r = right.begin();

    while (l != left.end() && r != right.end())
    {
        if (l->first < r->first) pair.push_back(*l++);
        else                     pair.push_back(*r++);
    }
    pair.insert(pair.end(), l, left.end());
    pair.insert(pair.end(), r, right.end());
}

void q_splitPair(Deque &main, Deque &insert, DeqPair &pair)
{
    DeqPair::iterator i = pair.begin();

    main.clear();
    while (i != pair.end())
    {
        main.push_back(i->first);
        insert.push_back(i->second);
        i++;
    }
}

typename Deque::iterator q_binarySearch(Deque &main, int target)
{
    typename Deque::iterator  mid, begin, end;
    begin = main.begin();
    end = main.end();
    
    while (begin < end)
    {
        mid = begin + (end - begin) / 2;
        
        if (*mid < target)  begin = ++mid;
        else                end = mid;
    }
    return mid;
}

void q_binaryInsertionSort(Deque &main, Deque &insert, Vector &seq, int &unpair)
{
    Deque::iterator it_main;

    for (Vector::iterator it_seq = seq.begin() ; it_seq != seq.end(); it_seq++)
    {
        it_main = q_binarySearch(main, insert[*it_seq]);
        main.insert(it_main, insert[*it_seq]);
    }
    if (unpair >= 0)
    {
        it_main = q_binarySearch(main, unpair);
        main.insert(it_main,  unpair);
    }
}

void Ford_John_Sort(Deque &main)
{
    clock_t start, init_t, pair_t, merge_t, split_t, seq_t, insert_t;
    if (main.size() < 2) return ;

    start = clock();
    int unpair = -1;
    Deque insert;
    DeqPair pair;
    Vector seq;
    init_t = clock();
    
    q_pairSort(main, pair, unpair); 
    pair_t = clock();

    q_mergeSortPair(pair);
    merge_t = clock();

    q_splitPair(main, insert, pair);
    split_t = clock();

    getInsertSeq(seq, static_cast<int>(insert.size()));
    seq_t = clock();

    q_binaryInsertionSort(main, insert, seq, unpair);
    insert_t = clock();

    COUT << "\nInit time      : " << static_cast<double>(init_t - start) / CLOCKS_PER_SEC * 1e6 << "\n"; 
    COUT << "Pair sort time : " << static_cast<double>(pair_t - init_t) / CLOCKS_PER_SEC * 1e6 << "\n"; 
    COUT << "Merge sort time: " << static_cast<double>(merge_t - pair_t) / CLOCKS_PER_SEC * 1e6 << "\n"; 
    COUT << "Split time     : " << static_cast<double>(split_t - merge_t) / CLOCKS_PER_SEC * 1e6 << "\n";
    COUT << "Get seq time   : " << static_cast<double>(seq_t - split_t) / CLOCKS_PER_SEC * 1e6 << "\n";
    COUT << "Search & Insert: " << static_cast<double>(insert_t - seq_t) / CLOCKS_PER_SEC * 1e6 << "\n\n"; 
}