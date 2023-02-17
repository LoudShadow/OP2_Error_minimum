#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "op_seq.h"

#include "kernel_sum.h"

int main(int argc, char **argv){
    op_init(argc, argv, 2);

    int cell [4] = {0,1,2,3};

    op_set nodes = op_decl_set(4, "nodes");
    op_set cells = op_decl_set(1, "nodes");

    op_map pcell = op_decl_map(cells,  nodes, 4, cell,   "pcell"  );
    
    double v [4] = {0.1,0.1,0.1,0.2};
    double cv [4] = {0};

    op_dat p_v = op_decl_dat(nodes, 1, "double", v, "p_v");
    op_dat p_cv = op_decl_dat(cells, 1, "double", cv , "p_cv");

    op_par_loop(kernel_sum, "add_dv", cells,
            op_arg_dat(p_cv, -1 ,OP_ID, 1, "double", OP_RW),
            op_arg_dat(p_v, 0, pcell, 1, "double", OP_READ));

    printf(" %e %e %e %e ",v[0],v[1],v[2],v[3]);
    op_exit();
}