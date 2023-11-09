long long sum;
void traval(int i) {
    if(i == -1) return;
    if(left__[i] == -1 && right__[i] == -1) sum += b[i];
    traval(left__[i]);
    traval(right__[i]);
}

// Travel from root
travel(pos[n-1]);
