    if(ans[i - pos[j]] == 0){
                            count++;
                        }
                        if(max_len < (i+1)-pos[j]){
                            max_len = (i+1) - pos[j];
                        }
                        ans[(i+1) - pos[j]]++;