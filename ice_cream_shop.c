/*
insanlar kuyruða girdiginde ilk siraya giren kişi ilk hizmet alacagindan dolayi yani first in
first out mantigi oldugu için kuyruk(queue) yapisini kullandim.Bu yapiyi servecustomers komutunu kullanirken kullandim.
günlük raporu oluþtururken ilk hizmet verdiðimiz kiþiyi son olarak kaydettüðimiz için output dosyasýna bu yüzden de stack yapisi kullandim.
Çünkü stack last in first out mantigiyla çalisiyor. Stack ve queue yapilarini arraylarla kodladim.

*/


#include<stdio.h>
#include<string.h>

struct customer_file_file_ino
{
    char group;
    char customer_name[11];
};

struct customer_file_file_ino customer_report[100];
int customer_report_index = 0;

char el_tail[11][11], ad_tail[11][11], ch_tail[11][11];
int el_write = 0, ad_write = 0, ch_write = 0;
int el_read = 0, ad_read = 0, ch_read = 0;

FILE* file_in, *file_out;

char order[40];
char customer_name[40], age_group;
int buffer;
char location_tab;
int count;

//***************************************************************
char c_serve_customer()
{

    if (ch_read != ch_write)
    {
        customer_report[customer_report_index].group = 'C';
        strcpy(customer_report[customer_report_index].customer_name,
        ch_tail[ch_read++]);
    }
    else
    {
        customer_report[customer_report_index].group = 'C';
        strcpy(customer_report[customer_report_index].customer_name,
        "*****");
    }
    if (ch_read >= 11)
        ch_read = 0;
    customer_report_index++;

    return '    ';
}

char e_serve_customer()
{

    if (el_read < el_write)
    {

        customer_report[customer_report_index].group = 'E';
        strcpy(customer_report[customer_report_index].customer_name,
        el_tail[el_read++]);
    }
    else
    {

        customer_report[customer_report_index].group = 'E';
        strcpy(customer_report[customer_report_index].customer_name,
        "*****");
    }

    if (el_read >= 11)
        el_read = 0;
    customer_report_index++;

    return '    ';

}



char a_serve_customer()
{

    if (ad_read < ad_write)
    {
        customer_report[customer_report_index].group = 'A';
        strcpy(customer_report[customer_report_index].customer_name,
        ad_tail[ad_read++]);
    }
    else
    {
        customer_report[customer_report_index].group = 'A';
        strcpy(customer_report[customer_report_index].customer_name,
        "*****");
    }
    if (ad_read >= 11)
        ad_read = 0;
    customer_report_index++;

    return '    ';
}



void e_new_customer()
{

    strcpy(el_tail[el_write++], customer_name);
    if (el_write >= 11)
        el_write = 0;
}

void a_new_customer()
{

    strcpy(ad_tail[ad_write++], customer_name);
    if (ad_write >= 11)
        ad_write = 0;
}

void c_new_customer()
{

    strcpy(ch_tail[ch_write++], customer_name);
    if (ch_write >= 11)
        ch_write = 0;
}

//**************************************************************
int
main()
{

    file_in = fopen("input.txt", "r");


    buffer = fscanf(file_in, "%s", order);
    while (buffer == 1)
    {
        fscanf(file_in, "%c\t", &location_tab);


        if (strcmp("ServeCustomers", order) == 0)
        {
            fscanf(file_in, "%c\t%d", &age_group, &count);


            if (age_group == 'E')
            {

                while (count--)
                {

                    e_serve_customer();

                }

            }

            else if (age_group == 'A')
            {
                while (count--)
                {

                    a_serve_customer();
                }

            }

            else if (age_group == 'C')
            {

                while (count--)
                {

                    c_serve_customer();

                }

            }

            else
            {
                break;
            }

        }

        else if (strcmp("NewCustomer", order) == 0)
        {
            fscanf(file_in, "%c%s", &age_group, &customer_name);

            if (age_group == 'E')
            {

                e_new_customer();
            }

            else if (age_group == 'A')
            {

            a_new_customer();

            }

            else if (age_group == 'C')
            {

                c_new_customer();

            }

            else
            {
                break;
            }
        }

        else
        {
            break;
        }
        buffer = fscanf(file_in, "%s", order);
    }
    fclose(file_in);
//********************************************************
    file_out = fopen("output.txt", "w");

    while (customer_report_index--)
    {
        fprintf(file_out, "%c\t%s\n", customer_report[customer_report_index].group, customer_report[customer_report_index].customer_name);
    }
    fclose(file_out);
}
