#ifndef SIMPLE_STAT_H
#define SIMPLE_STAT_H
#include <iostream>
#include <bits/stdc++.h>
#include "linkenode.h"

template <typename E>
class Simple_stat {
    private:
        LinkNode<E> *end, *head;
        int size = 0;
        double total = 0;
        double min;
        double mean;
        double max;
        double SD;
    public:
        // Constructors
        Simple_stat()
        {
            end = head = NULL;
        }

        /* Constructor Iterators */
        template <typename T, size_t size>
        Simple_stat(std::array<T, size> arr)
        {
            end = head = NULL;
            for(auto it = arr.begin(); it != arr.end(); ++it)
                this->append(*it);
            this->calc_SD();
        }

        Simple_stat(E *val, int size)
        {
            end = head = NULL;
            for (int i = 0; i < size; i++)
            {
                this->append(val[i], false);
            }
            calc_SD();
        }

        
        Simple_stat(std::vector<E> &vec)
        {
            end = head = NULL;
            for(double i : vec)
                this->append(i, false);
            calc_SD();
        }

        
        Simple_stat(std::set<E> &s)
        {
            end = head = NULL;
            for(double i : s)
                this->append(i, false);
            calc_SD();
        }

        /* End Constructor Iterators */

        
        void append(E val, bool recalc_SD=true)
        {
            LinkNode<E> *n = new LinkNode<E>(val);
            if (head == NULL)
            {
                head = n;
                end = head;
                min = val;
                max = val;
                mean = val / 1;
                total += val;
                size += 1;
                return;
            }
            this->update_data(val);
            if (recalc_SD == true)
                this->calc_SD();
            end->next = n;
            end = end->next;
        }

        
        void removem(E val, int m)
        {
            //Find number of available specified elements
            int i = 0;
            int n = 0;
            int y = 0;
            std::vector<int> elements(m);
            end=head;
            while(end!=NULL)
            {
                if(val == end->element)
                {
                    elements[y] = i;
                    i++;
                    n++;
                    y++;
                    end = end->next;
                }
                else{
                    i++;
                    end = end->next;
                }
            }

            // Remove element(s)
            end=head;
            LinkNode<E> *temp=head;
            LinkNode<E> *prev=head;
            int x = 0;
            i = 0;
            if(m<=n)
            {
                while(x<m)
                {
                    if(i==elements[x] && end==head)
                    {
                        head=head->next;
                        end=head;
                        prev=head;
                        i+=1;
                        x+=1;
                    }
                    else if(i==elements[x] && end!=head)
                    {
                        temp=end;
                        prev->next=end->next;
                        end=end->next;
                        delete temp;
                        i+=1;
                        x+=1;
                    }
                    else
                    {
                        if(end->next != NULL)
                        {
                            prev=end;
                            end=end->next;
                            i+=1;
                        }
                        else
                            i++;
                    }
                }

                //Update Data
                this->total = (total - (val*m));
                this->size = (size - m);
                this->mean = total/size;
                this->calc_SD();

                if(val==this->min)
                {
                    end=head;
                    this->min=end->element;
                    while(end!=NULL)
                    {
                        if(end->element<=this->min)
                        {
                            this->min=end->element;
                            end=end->next;
                        }
                        else
                            end=end->next;
                    }

                }
                else if(val==this->max)
                {
                    end=head;
                    this->max=end->element;
                    while(end!=NULL)
                    {
                        if(end->element>=this->max)
                        {
                            this->max=end->element;
                            end=end->next;
                        }
                        else
                            end=end->next;
                    }
                }
            }
            else
            std::cout << "Insufficient amount of elements\n";
        }
        
        void  empty()
        {
            while(head != NULL)
            {
                    end = head;
                    head = head->next;
                    delete end;
            }
            this->min=0;
            this->max=0;
            this->total=0;
            this->mean=0;
            this->size=0;
            this->SD=0;
        }

        
        void print()
        {
        LinkNode<E>* curr = head;
        while(curr != NULL)
            {
                std::cout << curr->element << " " << std::endl;
                curr = curr->next;
            }
        }


        /* Getters */
        E get_min()
        {
            return min;
        }


        E get_max()
        {
            return max;
        }


        
        E get_mean()
        {
            return mean;
        }

        
        E get_SD()
        {
            return SD;
        }


        
        int length_total()
        {
            return size;
        }

        
        int length_unique()
        {
            return unique_set().size();
        }

        
        std::pair<E, E> search(double val)
        {
            std::pair<E, E> num_reps;
            int rep_first = -1;
            int rep_total = 0;
            int count = -1;
            LinkNode<E>* curr = head;
            while (curr != NULL) {
                count++;
                if (curr->element == val) {
                    rep_total += 1;
                    if (rep_first < 0) {
                        rep_first = count;
                    }
                }
                curr = curr->next;
            }
            if (rep_first < 0) {
                std::cout << val << " does not exist in this data set." << std::endl;
            }
            else {
                num_reps.first = rep_first;
                num_reps.second = rep_total;
                std::cout << num_reps.first << ", " << num_reps.second << std::endl;
            }
            return num_reps;
        }


        /* End Getters */
        std::set<E> unique_set()
        {
            std::set<E> unique;
            LinkNode<E>* curr = head;
            while (curr != NULL) {
                unique.insert(curr->element);
                curr = curr->next;
            }
            return unique;

        }


        E operator[](int index)
        {
        int i;
        LinkNode<E> *runner = head;

        if (index > size - 1)
        {
            throw std::out_of_range("Out of range");
        }

        for (int i = 0; i < index; i++)
        {
            runner = runner->next;
        }
        return runner->element;
        }


        void calc_SD()
        {
            double deviation;
            double variance = 0;
            LinkNode<E>* curr = head;
            while (curr != NULL) {
                deviation = (curr->element - this->get_mean());
                variance += (deviation * deviation);
                curr = curr->next;
            }
            variance = variance / this->length_total();
            this->SD = sqrt(variance);
        }


        double sqrt(double val)
        {
            double base = val / 2;
            double temp = 0;

            while (base != temp) {
                temp = base;
                base = ((val / temp) + temp) / 2;
            }
            return base;
        }


        void print_unique()
        {
            std::set<E> unique = unique_set();
            std::cout << "Unique numbers: ";
            for (auto it = unique.begin(); it != unique.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }


        void check_data()
        {
            std::cout << "Total: " << total << std::endl;
            std::cout << "Length: " << this->length_total() << std::endl;
            std::cout << "Min: " << this->get_min() << std::endl;
            std::cout << "Max: " << this->get_max() << std::endl;
            std::cout << "Mean: " << this->get_mean() << std::endl;
            std::cout << "Standard Deviation: " << this->get_SD() << std::endl;
            std::cout << "# of Unique Elements: " << this->length_unique() << std::endl;
            this->print_unique();
        }


        void update_data(E val)
        {
        this->total += val;
        this->size += 1;
        this->mean = total / size;
        if (val < this->min)
        {
            this->min = val;
        }
        if (val > this->max)
        {
            this->max = val;
        }
        }


        template <typename T>
        void feed(T val)
        {
            for(auto it = val.begin(); it != val.end(); ++it)
                this->append(*it);
            this->calc_SD();
        }

};

#endif // SIMPLE_STAT_H
