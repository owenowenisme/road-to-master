"addi t0, t0, 16;"
"addi %[arith_cnt], %[arith_cnt], 1;"
"vsetvli t1, t0, e16;"
"vsetvli t2, t0, e16;"
"addi %[others_cnt], %[others_cnt], 2;"
"vle16.v v0 , 0(%[x]);"
"vle16.v v1 , 0(%[h]);"
"addi %[lw_cnt], %[lw_cnt], 2;"
"vadd.vv v0, v0, v1;"
"addi %[arith_cnt], %[arith_cnt], 1;"
"vse16.v v0, 0(%[y]);"
"addi %[sw_cnt], %[sw_cnt], 1;"
"addi %[x], %[x], 16;"
"addi %[h], %[h], 16;"
"addi %[y], %[y], 16;"
"addi %[arith_cnt], %[arith_cnt], 3;"
"vle16.v v0 , 0(%[x]);"
"vle16.v v1 , 0(%[h]);"
"addi %[lw_cnt], %[lw_cnt], 2;"
"vadd.vv v0, v0, v1;"
"addi %[arith_cnt], %[arith_cnt], 1;"
"vse16.v v0, 0(%[y]);"
"addi %[sw_cnt], %[sw_cnt], 1;"