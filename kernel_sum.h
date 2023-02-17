inline void kernel_sum(double* sV,const double* V){
    printf(" %e \n",V[0]);
    for (int i = 0; i < 4; i++)
    {
        sV[0] += V[i];
    }
}