#include <iostream>

#define DEBUG 0

using namespace std;

struct page
{
  int page;
  int second_chance;
};

int exec(int num_frames)
{
  page ptb[num_frames];
  for (int i = 0; i < num_frames; i++)
  {
    ptb[i].second_chance = 0;
    ptb[i].page = -1;
  }
  page *ptr = ptb;

  int ref_string[] = {1, 2, 3, 2, 4, 5, 1, 6, 2, 1, 3, 2, 7, 6, 3, 2, 2, 1, 3, 2, 6};
  int size = 21;
  int ptr_index = 0;

  bool found = false;
  int num_page_faults = 0;

  for (int i = 0; i < 21; i++)
  {
    found = false;
    //find page
    for (int j = 0; j < num_frames; j++)
    {
      if (ptb[j].page == ref_string[i])
      {
        found = true;
        ptb[j].second_chance = 1;
        break;
      }
    }

    //not found, look for a page with second_chance == 0
    //cycle ptr through ptb
    if (!found)
      num_page_faults++;
    while (!found)
    {
      //cout << "At " << ptr_index << ", 2nd_chance: " << ptr->second_chance << "\n";
      if (ptr->second_chance == 0)
      {
        found = true;
        ptr->page = ref_string[i];
        ptr->second_chance = 0;
      }
      else
        ptr->second_chance--;

      if (ptr_index + 1 >= num_frames)
      {
        ptr_index = 0;
        ptr = ptb;
      }
      else
      {
        ptr_index++;
        ptr++;
      }
    }

    if (DEBUG)
    {
      cout << "Need: " << ref_string[i] << ", ";
      for (int j = 0; j < num_frames; j++)
      {
        if (j == ptr_index)
          cout << ">>[";
        else
          cout << "  [";
        cout << ptb[j].page << ";" << ptb[j].second_chance << "] ";
        if (j == num_frames - 1)
          cout << "\n";
      }
    }
  }

  return num_page_faults;
}

int main()
{
  for (int i = 1; i <= 7; i++)
  {
    cout << "Page faults for " << i << " frame(s): " << exec(i) << "\n";
  }
}
