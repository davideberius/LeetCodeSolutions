int hammingDistance(int x, int y) {
    int i, index = 1, ret = 0;
    int powers[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 13421772\
                      8, 268435456, 536870912, 1073741824, 2147483648};
    char x_binary[33], y_binary[33];

    x_binary[32] = y_binary[32] = '\0';
    if(x < 0){
        x_binary[0] = '1';
        x *= -1;
    }
    else{
        x_binary[0] = '0';
    }

    if(y < 0){
        y_binary[0] = '1';
        y *= -1;
    }
    else{
        y_binary[0] = '0';
    }

    if(x_binary[0] != y_binary[0])
        ret++;

    for(i = 30; i >= 0; i--){
        if(x >= powers[i]){
            x_binary[index] = '1';
            x -= powers[i];
        }
        else{
            x_binary[index] = '0';
        }

        if(y >= powers[i]){
            y_binary[index] = '1';
            y -= powers[i];
        }
        else{
            y_binary[index] = '0';
        }

        if(x_binary[index] != y_binary[index])
            ret++;

        index++;
    }
    
    return ret;
}
