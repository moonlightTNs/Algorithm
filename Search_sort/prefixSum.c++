#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    int st[n] = {};
    int en[n] = {};
    int _max = 0;
    for (int i = 0; i < n; i++)
    {
        int start = 0;
        int end = 0;
        cin >> start >> end;

        if (end > _max)
        {
            _max = end;
        }

        st[i] = start;
        en[i] = end;
    }
    _max = _max + 1;
    int _time[_max] = {};

    for (int i = 0; i < n; i++)
    {
        _time[st[i]] += 1;
        _time[en[i]+1] -= 1;
    }

  

    for (int i = 1; i <= _max; i++)
    {
        _time[i] = _time[i - 1] + _time[i];
    }


    for (int i = 0; i < _max; i++)
    {
        cout << _time[i] << " ";
    }


    cout << endl ;
    


    int _maxT = 0;
    int ans_start = 0;
    int ans_end = 0;
    for(int i = 0 ; i < _max; i++){
        if(_time[i] > _maxT){
            _maxT = _time[i];
            ans_start = i;
            ans_end = i;
        }
        else if (_time[i] == _maxT){
            if(i == ans_end + 1){
                ans_end = i;
            }
        }
        
    }
    cout << ans_start << " " << ans_end << " " << _maxT;


    return 0;
}