00, ,<,00
00,1, ,n1skip //
	n1skip, ,<,n1skip1  n1skip1,1,<,n1skip1  n1skip1,0,<,n1skip1  n1skip1, ,<,n1skip2
    	n1skip2,1, ,n1p1skip //
		n1p1skip, ,>,n1p1skip1
		n1p1skip1, ,>,n1p1skip2
		n1p1skip2,1,>,n1p1skip2  n1p1skip2,0,>,n1p1skip2  n1p1skip2, ,>,n1p1skip3
		n1p1skip3, ,>,n1p1skip4
		n1p1skip4, ,0,n1p1q1resf
    	n1skip2,0, ,n1p0skip //
		n1p0skip, ,>,n1p0skip1
		n1p0skip1, ,>,n1p0skip2
		n1p0skip2,1,>,n1p0skip2  n1p0skip2,0,>,n1p0skip2  n1p0skip2, ,>,n1p0skip3
              n1p0skip3, ,>,n1p0skip4
		n1p0skip4, ,1,n1p0q0resf
00,0, ,n0skip //
        n0skip, ,<,n0skip1  n0skip1,1,<,n0skip1  n0skip1,0,<,n0skip1  n0skip1, ,<,n0skip2
	n0skip2,1, ,n0p1skip //
		n0p1skip, ,>,n0p1skip1
		n0p1skip1, ,>,n0p1skip2
		n0p1skip2,1,>,n0p1skip2  n0p1skip2,0,>,n0p1skip2  n0p1skip2, ,>,n0p1skip3
		n0p1skip3, ,>,n0p1skip4
		n0p1skip4, ,1,n0p1q0resf
    	n0skip2,0, ,n0p0skip //
		n0p0skip, ,>,n0p0skip1
		n0p0skip1, ,>,n0p0skip2
		n0p0skip2,1,>,n0p0skip2  n0p0skip2,0,>,n0p0skip2  n0p0skip2, ,>,n0p0skip3
		n0p0skip3, ,>,n0p0skip4
		n0p0skip4, ,0,n0p0q0resf
// 1f
n1p1q1resf,0,<,n1p1q1skipf  n1p1q1resf,1,<,n1p1q1skipf 
	n1p1q1skipf, ,<,n1p1q1skip2f   
	n1p1q1skip2f, ,1,n1p1q1skip3f //
	n1p1q1skip3f,1,<,n1p1q1skip4f  n1p1q1skip3f,0,<,n1p1q1skip4f
		n1p1q1skip4f,1, ,n1p1q1skip5f //?
			n1p1q1skip5f, ,<,n1p1q1skip6f
			n1p1q1skip6f,1,<,n1p1q1skip6f  n1p1q1skip6f,0,<,n1p1q1skip6f  n1p1q1skip6f, ,<,n1p1q1skip7f
			n1p1q1skip7f, ,1,n1p1q1skip8f
			n1p1q1skip8f,1,<,n1p1q1skip9f  n1p1q1skip8f,0,<,n1p1q1skip9f //
				n1p1q1skip9f,1, ,n1p1q1put
				n1p1q1skip9f,0, ,n1p0q1put
				n1p1q1skip9f, , ,n1p_q1put
		n1p1q1skip4f,0, ,n0p1q1skip5f //?
			n0p1q1skip5f, ,<,n0p1q1skip6f
			n0p1q1skip6f,1,<,n0p1q1skip6f  n0p1q1skip6f,0,<,n0p1q1skip6f  n0p1q1skip6f, ,<,n0p1q1skip7f
			n0p1q1skip7f, ,1,n0p1q1skip8f
			n0p1q1skip8f,1,<,n0p1q1skip9f  n0p1q1skip8f,0,<,n0p1q1skip9f //
				n0p1q1skip9f,1, ,n0p1q1put
				n0p1q1skip9f,0, ,n0p0q1put
				n0p1q1skip9f, , ,n0p_q1put
		n1p1q1skip4f, , ,n_p1q1skip5f //?
			n_p1q1skip5f, ,>,n_p1q1skip6f
			n_p1q1skip6f,1,<,n_p1q1skip6f  n_p1q1skip6f,0,<,n_p1q1skip6f  n_p1q1skip6f, ,<,n_p1q1skip7f
			n_p1q1skip7f, ,1,n_p1q1skip8f
			n_p1q1skip8f,1,<,n_p1q1skip9f  n_p1q1skip8f,0,<,n_p1q1skip9f //
				n_p1q1skip9f,1, ,n_p1q1put
				n_p1q1skip9f,0, ,n_p0q1put
				n_p1q1skip9f, , ,n_p_q1put
// 2f
n1p0q0resf,0,<,n1p0q0skipf  n1p0q0resf,1,<,n1p0q0skipf 
	n1p0q0skipf, ,<,n1p0q0skip2f 
	n1p0q0skip2f, ,1,n1p0q0skip3f //
	n1p0q0skip3f,1,<,n1p0q0skip4f  n1p0q0skip3f,0,<,n1p0q0skip4f
		n1p0q0skip4f,1, ,n1p0q0skip5 //?
		n1p0q0skip4f,0, ,n0p0q0skip5 //?
		n1p0q0skip4f, , ,n_p0q0skip5 //?
// 3f
n0p1q0resf,0,<,n0p1q0skipf  n0p1q0resf,1,<,n0p1q0skipf 
	n0p1q0skipf, ,<,n0p1q0skip2f 
	n0p1q0skip2f, ,0,n0p1q0skip3f //
	n0p1q0skip3f,1,<,n0p1q0skip4f  n0p1q0skip3f,0,<,n0p1q0skip4f
		n0p1q0skip4f,1, ,n1p1q0skip5f //?
			n1p1q0skip5f, ,<,n1p1q0skip6f
			n1p1q0skip6f,1,<,n1p1q0skip6f  n1p1q0skip6f,0,<,n1p1q0skip6f  n1p1q0skip6f, ,<,n1p1q0skip7f
			n1p1q0skip7f, ,1,n1p1q0skip8f
			n1p1q0skip8f,1,<,n1p1q0skip9f  n1p1q0skip8f,0,<,n1p1q0skip9f //
				n1p1q0skip9f,1, ,n1p1q0put
				n1p1q0skip9f,0, ,n1p0q0put
				n1p1q0skip9f, , ,n1p_q0put
		n0p1q0skip4f,0, ,n0p1q0skip5f //?
			n0p1q0skip5f, ,<,n0p1q0skip6f
			n0p1q0skip6f,1,<,n0p1q0skip6f  n0p1q0skip6f,0,<,n0p1q0skip6f  n0p1q0skip6f, ,<,n0p1q0skip7f
			n0p1q0skip7f, ,1,n0p1q0skip8f
			n0p1q0skip8f,1,<,n0p1q0skip9f  n0p1q0skip8f,0,<,n0p1q0skip9f //
				n0p1q0skip9f,1, ,n0p1q0put
				n0p1q0skip9f,0, ,n0p0q0put
				n0p1q0skip9f, , ,n0p_q0put
		n0p1q0skip4f, , ,n_p1q0skip5f //?
			n_p1q0skip5f, ,>,n_p1q0skip6f
			n_p1q0skip6f,1,<,n_p1q0skip6f  n_p1q0skip6f,0,<,n_p1q0skip6f  n_p1q0skip6f, ,<,n_p1q0skip7f
			n_p1q0skip7f, ,1,n_p1q0skip8f
			n_p1q0skip8f,1,<,n_p1q0skip9f  n_p1q0skip8f,0,<,n_p1q0skip9f //
				n_p1q0skip9f,1, ,n_p1q0put
				n_p1q0skip9f,0, ,n_p0q0put
				n_p1q0skip9f, , ,n_p_q0put
// 4f
n0p0q0resf,0,<,n0p0q0skipf  n0p0q0resf,1,<,n0p0q0skipf 
	n0p0q0skipf, ,<,n0p0q0skip2f 
	n0p0q0skip2f, ,0,n0p0q0skip3f //
	n0p0q0skip3f,1,<,n0p0q0skip4f  n0p0q0skip3f,0,<,n0p0q0skip4f
		n0p0q0skip4f,1, ,n1p0q0skip5f //?
			n1p0q0skip5f, ,<,n1p0q0skip6f
			n1p0q0skip6f,1,<,n1p0q0skip6f  n1p0q0skip6f,0,<,n1p0q0skip6f  n1p0q0skip6f, ,<,n1p0q0skip7f
			n1p0q0skip7f, ,0,n1p0q0skip8f
			n1p0q0skip8f,1,<,n1p0q0skip9f  n1p0q0skip8f,0,<,n1p0q0skip9f //
				n1p0q0skip9f,1, ,n1p1q0put
				n1p0q0skip9f,0, ,n1p0q0put
				n1p0q0skip9f, , ,n1p_q0put
		n0p0q0skip4f,0, ,n0p0q0skip5f //?
			n0p0q0skip5f, ,<,n0p0q0skip6f
			n0p0q0skip6f,1,<,n0p0q0skip6f  n0p0q0skip6f,0,<,n0p0q0skip6f  n0p0q0skip6f, ,<,n0p0q0skip7f
			n0p0q0skip7f, ,0,n0p0q0skip8f
			n0p0q0skip8f,1,<,n0p0q0skip9f  n0p0q0skip8f,0,<,n0p0q0skip9f //
				n0p0q0skip9f,1, ,n0p1q0put
				n0p0q0skip9f,0, ,n0p0q0put
				n0p0q0skip9f, , ,n0p_q0put
		n0p0q0skip4f, , ,n_p0q0skip5f //?
			n_p0q0skip5f, ,>,n_p0q0skip6f
			n_p0q0skip6f,1,<,n_p0q0skip6f  n_p0q0skip6f,0,<,n_p0q0skip6f  n_p0q0skip6f, ,<,n_p0q0skip7f
			n_p0q0skip7f, ,0,n_p0q0skip8f
			n_p0q0skip8f,1,<,n_p0q0skip9f  n_p0q0skip8f,0,<,n_p0q0skip9f //
				n_p0q0skip9f,1, ,n_p1q0put
				n_p0q0skip9f,0, ,n_p0q0put
				n_p0q0skip9f, , ,n_p_q0put
// 1
n0p0q0res,0,0,n0p0q0skip  n0p0q0res,1,1,n0p0q0skip 
	n0p0q0skip, ,<,n0p0q0skip1 n0p0q0skip,1,<,n0p0q0skip  n0p0q0skip,0,<,n0p0q0skip
	n0p0q0skip1,1,<,n0p0q0skip1 n0p0q0skip1,0,<,n0p0q0skip1  n0p0q0skip1, , ,n0p0q0skip2  
	n0p0q0skip2,1,<,n0p0q0skip2  n0p0q0skip2,0,<,n0p0q0skip2  
	n0p0q0skip2, ,0,n0p0q0skip3 //
	n0p0q0skip3,1,<,n0p0q0skip4  n0p0q0skip3,0,<,n0p0q0skip4
		n0p0q0skip4,1, ,n1p0q0skip5 //?
			n1p0q0skip5, ,<,n1p0q0skip6
			n1p0q0skip6,1,<,n1p0q0skip6  n1p0q0skip6,0,<,n1p0q0skip6  n1p0q0skip6, ,<,n1p0q0skip7			
n1p0q0skip7,1,<,n1p0q0skip7  n1p0q0skip7,0,<,n1p0q0skip7
			n1p0q0skip7, ,0,n1p0q0skip8
			n1p0q0skip8,1,<,n1p0q0skip9  n1p0q0skip8,0,<,n1p0q0skip9 //
				n1p0q0skip9,1, ,n1p1q0put
				n1p0q0skip9,0, ,n1p0q0put
				n1p0q0skip9, , ,n1p_q0put
		n0p0q0skip4,0, ,n0p0q0skip5 //?
			n0p0q0skip5, ,<,n0p0q0skip6
			n0p0q0skip6,1,<,n0p0q0skip6  n0p0q0skip6,0,<,n0p0q0skip6  n0p0q0skip6, ,<,n0p0q0skip7
n0p0q0skip7,1,<,n0p0q0skip7  n0p0q0skip7,0,<,n0p0q0skip7
			n0p0q0skip7, ,0,n0p0q0skip8
			n0p0q0skip8,1,<,n0p0q0skip9  n0p0q0skip8,0,<,n0p0q0skip9 //
				n0p0q0skip9,1, ,n0p1q0put
				n0p0q0skip9,0, ,n0p0q0put
				n0p0q0skip9, , ,n0p_q0put
		n0p0q0skip4, , ,n_p0q0skip5 //?
			n_p0q0skip5, ,>,n_p0q0skip6
			n_p0q0skip6,1,<,n_p0q0skip6  n_p0q0skip6,0,<,n_p0q0skip6  n_p0q0skip6, ,<,n_p0q0skip7
n_p0q0skip7,1,<,n_p0q0skip7 n_p0q0skip7,0,<,n_p0q0skip7
			n_p0q0skip7, ,0,n_p0q0skip8
			n_p0q0skip8,1,<,n_p0q0skip9  n_p0q0skip8,0,<,n_p0q0skip9 //
				n_p0q0skip9,1, ,n_p1q0put
				n_p0q0skip9,0, ,n_p0q0put
				n_p0q0skip9, , ,n_p_q0put
// 2
n0p1q0res,0,0,n0p1q0skip  n0p1q0res,1,1,n0p1q0skip 
	n0p1q0skip, ,<,n0p1q0skip1 n0p1q0skip,1,<,n0p1q0skip  n0p1q0skip,0,<,n0p1q0skip
	n0p1q0skip1,1,<,n0p1q0skip1 n0p1q0skip1,0,<,n0p1q0skip1  n0p1q0skip1, , ,n0p1q0skip2  
	n0p1q0skip2,1,<,n0p1q0skip2  n0p1q0skip2,0,<,n0p1q0skip2  
	n0p1q0skip2, ,0,n0p1q0skip3 //
	n0p1q0skip3,1,<,n0p1q0skip4  n0p1q0skip3,0,<,n0p1q0skip4
		n0p1q0skip4,1, ,n1p1q0skip5 //?
			n1p1q0skip5, ,<,n1p1q0skip6
			n1p1q0skip6,1,<,n1p1q0skip6  n1p1q0skip6,0,<,n1p1q0skip6  n1p1q0skip6, ,<,n1p1q0skip7
n1p1q0skip7,1,<,n1p1q0skip7 n1p1q0skip7,0,<,n1p1q0skip7
			n1p1q0skip7, ,1,n1p1q0skip8
			n1p1q0skip8,1,<,n1p1q0skip9  n1p1q0skip8,0,<,n1p1q0skip9 //
				n1p1q0skip9,1, ,n1p1q0put
				n1p1q0skip9,0, ,n1p0q0put
				n1p1q0skip9, , ,n1p_q0put
		n0p1q0skip4,0, ,n0p1q0skip5 //?
			n0p1q0skip5, ,<,n0p1q0skip6
			n0p1q0skip6,1,<,n0p1q0skip6  n0p1q0skip6,0,<,n0p1q0skip6  n0p1q0skip6, ,<,n0p1q0skip7
n0p1q0skip7,1,<,n0p1q0skip7 n0p1q0skip7,0,<,n0p1q0skip7
			n0p1q0skip7, ,1,n0p1q0skip8
			n0p1q0skip8,1,<,n0p1q0skip9  n0p1q0skip8,0,<,n0p1q0skip9 //
				n0p1q0skip9,1, ,n0p1q0put
				n0p1q0skip9,0, ,n0p0q0put
				n0p1q0skip9, , ,n0p_q0put
		n0p1q0skip4, , ,n_p1q0skip5 //?
			n_p1q0skip5, ,>,n_p1q0skip6
			n_p1q0skip6,1,<,n_p1q0skip6  n_p1q0skip6,0,<,n_p1q0skip6  n_p1q0skip6, ,<,n_p1q0skip7
n_p1q0skip7,1,<,n_p1q0skip7 n_p1q0skip7,0,<,n_p1q0skip7
			n_p1q0skip7, ,1,n_p1q0skip8
			n_p1q0skip8,1,<,n_p1q0skip9  n_p1q0skip8,0,<,n_p1q0skip9 //
				n_p1q0skip9,1, ,n_p1q0put
				n_p1q0skip9,0, ,n_p0q0put
				n_p1q0skip9, , ,n_p_q0put
// 3
n1p0q0res,0,0,n1p0q0skip  n1p0q0res,1,1,n1p0q0skip 
	n1p0q0skip, ,<,n1p0q0skip1 n1p0q0skip,1,<,n1p0q0skip  n1p0q0skip,0,<,n1p0q0skip
	n1p0q0skip1,1,<,n1p0q0skip1 n1p0q0skip1,0,<,n1p0q0skip1  n1p0q0skip1, , ,n1p0q0skip2  
	n1p0q0skip2,1,<,n1p0q0skip2  n1p0q0skip2,0,<,n1p0q0skip2  
	n1p0q0skip2, ,1,n1p0q0skip3 //
	n1p0q0skip3,1,<,n1p0q0skip4  n1p0q0skip3,0,<,n1p0q0skip4
		n1p0q0skip4,1, ,n1p0q0skip5 //?		
		n1p0q0skip4,0, ,n0p0q0skip5 //?
		n1p0q0skip4, , ,n_p0q0skip5 //?
// 4			
n1p1q1res,0,0,n1p1q1skip  n1p1q1res,1,1,n1p1q1skip 
	n1p1q1skip, ,<,n1p1q1skip1 n1p1q1skip,1,<,n1p1q1skip  n1p1q1skip,0,<,n1p1q1skip
	n1p1q1skip1,1,<,n1p1q1skip1 n1p1q1skip1,0,<,n1p1q1skip1  n1p1q1skip1, , ,n1p1q1skip2  
	n1p1q1skip2,1,<,n1p1q1skip2  n1p1q1skip2,0,<,n1p1q1skip2  
	n1p1q1skip2, ,1,n1p1q1skip3 //
	n1p1q1skip3,1,<,n1p1q1skip4  n1p1q1skip3,0,<,n1p1q1skip4
		n1p1q1skip4,1, ,n1p1q1skip5 //?
			n1p1q1skip5, ,<,n1p1q1skip6
			n1p1q1skip6,1,<,n1p1q1skip6  n1p1q1skip6,0,<,n1p1q1skip6  n1p1q1skip6, ,<,n1p1q1skip7
n1p1q1skip7,1,<,n1p1q1skip7 n1p1q1skip7,0,<,n1p1q1skip7
			n1p1q1skip7, ,1,n1p1q1skip8
			n1p1q1skip8,1,<,n1p1q1skip9  n1p1q1skip8,0,<,n1p1q1skip9 //
				n1p1q1skip9,1, ,n1p1q1put
				n1p1q1skip9,0, ,n1p0q1put
				n1p1q1skip9, , ,n1p_q1put
		n1p1q1skip4,0, ,n0p1q1skip5 //?
			n0p1q1skip5, ,<,n0p1q1skip6
			n0p1q1skip6,1,<,n0p1q1skip6  n0p1q1skip6,0,<,n0p1q1skip6  n0p1q1skip6, ,<,n0p1q1skip7
n0p1q1skip7,1,<,n0p1q1skip7 n0p1q1skip7,0,<,n0p1q1skip7
			n0p1q1skip7, ,1,n0p1q1skip8
			n0p1q1skip8,1,<,n0p1q1skip9  n0p1q1skip8,0,<,n0p1q1skip9 //
				n0p1q1skip9,1, ,n0p1q1put
				n0p1q1skip9,0, ,n0p0q1put
				n0p1q1skip9, , ,n0p_q1put
		n1p1q1skip4, , ,n_p1q1skip5 //?
			n_p1q1skip5, ,>,n_p1q1skip6
			n_p1q1skip6,1,<,n_p1q1skip6  n_p1q1skip6,0,<,n_p1q1skip6  n_p1q1skip6, ,<,n_p1q1skip7
n_p1q1skip7,1,<,n_p1q1skip7 n_p1q1skip7,0,<,n_p1q1skip7
			n_p1q1skip7, ,1,n_p1q1skip8
			n_p1q1skip8,1,<,n_p1q1skip9  n_p1q1skip8,0,<,n_p1q1skip9 //
				n_p1q1skip9,1, ,n_p1q1put
				n_p1q1skip9,0, ,n_p0q1put
				n_p1q1skip9, , ,n_p_q1put
// 5
n1p1q0res,0,0,n1p1q0skip  n1p1q0res,1,1,n1p1q0skip 
	n1p1q0skip, ,<,n1p1q0skip1 n1p1q0skip,1,<,n1p1q0skip  n1p1q0skip,0,<,n1p1q0skip
	n1p1q0skip1,1,<,n1p1q0skip1 n1p1q0skip1,0,<,n1p1q0skip1  n1p1q0skip1, , ,n1p1q0skip2  
	n1p1q0skip2,1,<,n1p1q0skip2  n1p1q0skip2,0,<,n1p1q0skip2  
	n1p1q0skip2, ,1,n1p1q0skip3 //
	n1p1q0skip3,1,<,n1p1q0skip4  n1p1q0skip3,0,<,n1p1q0skip4
		n1p1q0skip4,1, ,n1p1q0skip5 //?		
		n1p1q0skip4,0, ,n0p1q0skip5 //?		
		n1p1q0skip4, , ,n_p1q0skip5 //?
// 6			
n1p0q1res,0,0,n1p0q1skip  n1p0q1res,1,1,n1p0q1skip 
	n1p0q1skip, ,<,n1p0q1skip1 n1p0q1skip,1,<,n1p0q1skip  n1p0q1skip,0,<,n1p0q1skip
	n1p0q1skip1,1,<,n1p0q1skip1 n1p0q1skip1,0,<,n1p0q1skip1  n1p0q1skip1, , ,n1p0q1skip2  
	n1p0q1skip2,1,<,n1p0q1skip2  n1p0q1skip2,0,<,n1p0q1skip2  
	n1p0q1skip2, ,1,n1p0q1skip3 //
	n1p0q1skip3,1,<,n1p0q1skip4  n1p0q1skip3,0,<,n1p0q1skip4
		n1p0q1skip4,1, ,n1p0q1skip5 //?
			n1p0q1skip5, ,<,n1p0q1skip6
			n1p0q1skip6,1,<,n1p0q1skip6  n1p0q1skip6,0,<,n1p0q1skip6  n1p0q1skip6, ,<,n1p0q1skip7
n1p0q1skip7,1,<,n1p0q1skip7 n1p0q1skip7,0,<,n1p0q1skip7
			n1p0q1skip7, ,0,n1p0q1skip8
			n1p0q1skip8,1,<,n1p0q1skip9  n1p0q1skip8,0,<,n1p0q1skip9 //
				n1p0q1skip9,1, ,n1p1q1put
				n1p0q1skip9,0, ,n1p0q1put
				n1p0q1skip9, , ,n1p_q1put
		n1p0q1skip4,0, ,n0p0q1skip5 //?
			n0p0q1skip5, ,<,n0p0q1skip6
			n0p0q1skip6,1,<,n0p0q1skip6  n0p0q1skip6,0,<,n0p0q1skip6  n0p0q1skip6, ,<,n0p0q1skip7
n0p0q1skip7,1,<,n0p0q1skip7 n0p0q1skip7,0,<,n0p0q1skip7
			n0p0q1skip7, ,0,n0p0q1skip8
			n0p0q1skip8,1,<,n0p0q1skip9  n0p0q1skip8,0,<,n0p0q1skip9 //
				n0p0q1skip9,1, ,n0p1q1put
				n0p0q1skip9,0, ,n0p0q1put
				n0p0q1skip9, , ,n0p_q1put
		n1p0q1skip4, , ,n_p0q1skip5 //?
			n_p0q1skip5, ,>,n_p0q1skip6
			n_p0q1skip6,1,<,n_p0q1skip6  n_p0q1skip6,0,<,n_p0q1skip6  n_p0q1skip6, ,<,n_p0q1skip7
n_p0q1skip7,1,<,n_p0q1skip7 n_p0q1skip7,0,<,n_p0q1skip7
			n_p0q1skip7, ,0,n_p0q1skip8
			n_p0q1skip8,1,<,n_p0q1skip9  n_p0q1skip8,0,<,n_p0q1skip9 //
				n_p0q1skip9,1, ,n_p1q1put
				n_p0q1skip9,0, ,n_p0q1put
				n_p0q1skip9, , ,n_p_q1put
// 7
n0p1q1res,0,0,n0p1q1skip  n0p1q1res,1,1,n0p1q1skip 
	n0p1q1skip, ,<,n0p1q1skip1 n0p1q1skip,1,<,n0p1q1skip  n0p1q1skip,0,<,n0p1q1skip
	n0p1q1skip1,1,<,n0p1q1skip1 n0p1q1skip1,0,<,n0p1q1skip1  n0p1q1skip1, , ,n0p1q1skip2  
	n0p1q1skip2,1,<,n0p1q1skip2  n0p1q1skip2,0,<,n0p1q1skip2  
	n0p1q1skip2, ,0,n0p1q1skip3 //
	n0p1q1skip3,1,<,n0p1q1skip4  n0p1q1skip3,0,<,n0p1q1skip4
		n0p1q1skip4,1, ,n1p1q1skip5 //?		
		n0p1q1skip4,0, ,n0p1q1skip5 //?		
		n0p1q1skip4, , ,n_p1q1skip5 //?
// 8			
n0p0q1res,0,0,n0p0q1skip  n0p0q1res,1,1,n0p0q1skip 
	n0p0q1skip, ,<,n0p0q1skip1 n0p0q1skip,1,<,n0p0q1skip  n0p0q1skip,0,<,n0p0q1skip
	n0p0q1skip1,1,<,n0p0q1skip1 n0p0q1skip1,0,<,n0p0q1skip1  n0p0q1skip1, , ,n0p0q1skip2  
	n0p0q1skip2,1,<,n0p0q1skip2  n0p0q1skip2,0,<,n0p0q1skip2  
	n0p0q1skip2, ,0,n0p0q1skip3 //
	n0p0q1skip3,1,<,n0p0q1skip4  n0p0q1skip3,0,<,n0p0q1skip4
		n0p0q1skip4,1, ,n1p0q1skip5 //?		
		n0p0q1skip4,0, ,n0p0q1skip5 //?
		n0p0q1skip4, , ,n_p0q1skip5 //?
// 9			
n_p1q1res,0,0,n_p1q1skip  n_p1q1res,1,1,n_p1q1skip  n_p1q1res, ,<,n_p1q1skip  
	n_p1q1skip, ,<,n_p1q1skip1 n_p1q1skip,1,<,n_p1q1skip  n_p1q1skip,0,<,n_p1q1skip
	n_p1q1skip1,1,<,n_p1q1skip1 n_p1q1skip1,0,<,n_p1q1skip1  n_p1q1skip1, , ,n_p1q1skip2  
	n_p1q1skip2,1,<,n_p1q1skip2  n_p1q1skip2,0,<,n_p1q1skip2  
	n_p1q1skip2, ,>,n_p1q1skip3 //
	n_p1q1skip3,1,<,n_p1q1skip4  n_p1q1skip3,0,<,n_p1q1skip4
		n_p1q1skip4,1, ,n1p1q1skip5 //?
		n_p1q1skip4,0, ,n0p1q1skip5 //?			
		n_p1q1skip4, , ,n_p1q1skip5 //?
// 10			
n_p1q0res,0,0,n_p1q0skip  n_p1q0res,1,1,n_p1q0skip  n_p1q0res, ,<,n_p1q0skip  
	n_p1q0skip, ,<,n_p1q0skip1 n_p1q0skip,1,<,n_p1q0skip  n_p1q0skip,0,<,n_p1q0skip
	n_p1q0skip1,1,<,n_p1q0skip1 n_p1q0skip1,0,<,n_p1q0skip1  n_p1q0skip1, , ,n_p1q0skip2  
	n_p1q0skip2,1,<,n_p1q0skip2  n_p1q0skip2,0,<,n_p1q0skip2  
	n_p1q0skip2, ,>,n_p1q0skip3 //
	n_p1q0skip3,1,<,n_p1q0skip4  n_p1q0skip3,0,<,n_p1q0skip4
		n_p1q0skip4,1, ,n1p1q0skip5 //?
		n_p1q0skip4,0, ,n0p1q0skip5 //?
		n_p1q0skip4, , ,n_p1q0skip5 //?
// 11			 
n_p0q1res,0,0,n_p0q1skip  n_p0q1res,1,1,n_p0q1skip  n_p0q1res, ,<,n_p0q1skip 
	n_p0q1skip, ,<,n_p0q1skip1 n_p0q1skip,1,<,n_p0q1skip  n_p0q1skip,0,<,n_p0q1skip
	n_p0q1skip1,1,<,n_p0q1skip1 n_p0q1skip1,0,<,n_p0q1skip1  n_p0q1skip1, , ,n_p0q1skip2  
	n_p0q1skip2,1,<,n_p0q1skip2  n_p0q1skip2,0,<,n_p0q1skip2  
	n_p0q1skip2, ,>,n_p0q1skip3 //
	n_p0q1skip3,1,<,n_p0q1skip4  n_p0q1skip3,0,<,n_p0q1skip4
		n_p0q1skip4,1, ,n1p0q1skip5 //?
		n_p0q1skip4,0, ,n0p0q1skip5 //?
		n_p0q1skip4, , ,n_p0q1skip5 //?
// 12		
n_p0q0res,0,0,n_p0q0skip  n_p0q0res,1,1,n_p0q0skip  n_p0q0res, ,<,n_p0q0skip 
	n_p0q0skip, ,<,n_p0q0skip1 n_p0q0skip,1,<,n_p0q0skip  n_p0q0skip,0,<,n_p0q0skip
	n_p0q0skip1,1,<,n_p0q0skip1 n_p0q0skip1,0,<,n_p0q0skip1  n_p0q0skip1, , ,n_p0q0skip2  
	n_p0q0skip2,1,<,n_p0q0skip2  n_p0q0skip2,0,<,n_p0q0skip2  
	n_p0q0skip2, ,>,n_p0q0skip3 //
	n_p0q0skip3,1,<,n_p0q0skip4  n_p0q0skip3,0,<,n_p0q0skip4
		n_p0q0skip4,1, ,n1p0q0skip5 //?
		n_p0q0skip4,0, ,n0p0q0skip5 //?
		n_p0q0skip4, , ,n_p0q0skip5 //?
//  13			
n1p_q1res,0,0,n1p_q1skip  n1p_q1res,1,1,n1p_q1skip 
	n1p_q1skip, ,<,n1p_q1skip1 n1p_q1skip,1,<,n1p_q1skip  n1p_q1skip,0,<,n1p_q1skip
	n1p_q1skip1,1,<,n1p_q1skip1 n1p_q1skip1,0,<,n1p_q1skip1  n1p_q1skip1, , ,n1p_q1skip2  
	n1p_q1skip2,1,<,n1p_q1skip2  n1p_q1skip2,0,<,n1p_q1skip2  
	n1p_q1skip2, ,1,n1p_q1skip3 //
	n1p_q1skip3,1,<,n1p_q1skip4  n1p_q1skip3,0,<,n1p_q1skip4
		n1p_q1skip4,1, ,n1p_q1skip5 //?
		n1p_q1skip4,0, ,n0p_q1skip5 //?
		n1p_q1skip4, , ,n_p_q1skip5 //?
// 14		
n1p_q0res,0,0,n1p_q0skip  n1p_q0res,1,1,n1p_q0skip 
	n1p_q0skip, ,<,n1p_q0skip1 n1p_q0skip,1,<,n1p_q0skip  n1p_q0skip,0,<,n1p_q0skip
	n1p_q0skip1,1,<,n1p_q0skip1 n1p_q0skip1,0,<,n1p_q0skip1  n1p_q0skip1, , ,n1p_q0skip2  
	n1p_q0skip2,1,<,n1p_q0skip2  n1p_q0skip2,0,<,n1p_q0skip2  
	n1p_q0skip2, ,1,n1p_q0skip3 //
	n1p_q0skip3,1,<,n1p_q0skip4  n1p_q0skip3,0,<,n1p_q0skip4
		n1p_q0skip4,1, ,n1p_q0skip5 //?
		n1p_q0skip4,0, ,n0p_q0skip5 //?
		n1p_q0skip4, , ,n_p_q0skip5 //?
// 15			
n0p_q1res,0,0,n0p_q1skip  n0p_q1res,1,1,n0p_q1skip 
	n0p_q1skip, ,<,n0p_q1skip1 n0p_q1skip,1,<,n0p_q1skip  n0p_q1skip,0,<,n0p_q1skip
	n0p_q1skip1,1,<,n0p_q1skip1 n0p_q1skip1,0,<,n0p_q1skip1  n0p_q1skip1, , ,n0p_q1skip2  
	n0p_q1skip2,1,<,n0p_q1skip2  n0p_q1skip2,0,<,n0p_q1skip2  
	n0p_q1skip2, ,0,n0p_q1skip3 //
	n0p_q1skip3,1,<,n0p_q1skip4  n0p_q1skip3,0,<,n0p_q1skip4
		n0p_q1skip4,1, ,n1p_q1skip5 //?
		n0p_q1skip4,0, ,n0p_q1skip5 //?
		n0p_q1skip4, , ,n_p_q1skip5 //?
// 16
n0p_q0res,0,0,n0p_q0skip  n0p_q0res,1,1,n0p_q0skip 
	n0p_q0skip, ,<,n0p_q0skip1 n0p_q0skip,1,<,n0p_q0skip  n0p_q0skip,0,<,n0p_q0skip
	n0p_q0skip1,1,<,n0p_q0skip1 n0p_q0skip1,0,<,n0p_q0skip1  n0p_q0skip1, , ,n0p_q0skip2  
	n0p_q0skip2,1,<,n0p_q0skip2  n0p_q0skip2,0,<,n0p_q0skip2  
	n0p_q0skip2, ,0,n0p_q0skip3 //
	n0p_q0skip3,1,<,n0p_q0skip4  n0p_q0skip3,0,<,n0p_q0skip4
		n0p_q0skip4,1, ,n1p_q0skip5 //?
		n0p_q0skip4,0, ,n0p_q0skip5 //?
		n0p_q0skip4, , ,n_p_q0skip5 //?
// 17			
n_p_q1res,0,0,n_p_q1skip  n_p_q1res,1,1,n_p_q1skip 
	n_p_q1skip, ,<,n_p_q1skip1 n_p_q1skip,1,<,n_p_q1skip  n_p_q1skip,0,<,n_p_q1skip
	n_p_q1skip1,1,<,n_p_q1skip1 n_p_q1skip1,0,<,n_p_q1skip1  n_p_q1skip1, , ,n_p_q1skip2  
	n_p_q1skip2,1,<,n_p_q1skip2  n_p_q1skip2,0,<,n_p_q1skip2  
	n_p_q1skip2, ,>,n_p_q1skip3 //
	n_p_q1skip3,1,<,n_p_q1skip4  n_p_q1skip3,0,<,n_p_q1skip4
		n_p_q1skip4,1, ,n1p_q1skip5 //?
			n1p_q1skip5, ,<,n1p_q1skip6
			n1p_q1skip6,1,<,n1p_q1skip6  n1p_q1skip6,0,<,n1p_q1skip6  n1p_q1skip6, ,<,n1p_q1skip7
n1p_q1skip7,1,<,n1p_q1skip7 n1p_q1skip7,0,<,n1p_q1skip7
			n1p_q1skip7, ,>,n1p_q1skip8
			n1p_q1skip8,1,<,n1p_q1skip9  n1p_q1skip8,0,<,n1p_q1skip9 //
				n1p_q1skip9,1, ,n1p1q1put
				n1p_q1skip9,0, ,n1p0q1put
				n1p_q1skip9, , ,n1p_q1put
		n_p_q1skip4,0, ,n0p_q1skip5 //?
			n0p_q1skip5, ,<,n0p_q1skip6
			n0p_q1skip6,1,<,n0p_q1skip6  n0p_q1skip6,0,<,n0p_q1skip6  n0p_q1skip6, ,<,n0p_q1skip7
n0p_q1skip7,1,<,n0p_q1skip7 n0p_q1skip7,0,<,n0p_q1skip7
			n0p_q1skip7, ,>,n0p_q1skip8
			n0p_q1skip8,1,<,n0p_q1skip9  n0p_q1skip8,0,<,n0p_q1skip9 //
				n0p_q1skip9,1, ,n0p1q1put
				n0p_q1skip9,0, ,n0p0q1put
				n0p_q1skip9, , ,n0p_q1put
		n_p_q1skip4, , ,n_p_q1skip5 //?
			n_p_q1skip5, ,>,n_p_q1skip6
			n_p_q1skip6,1,<,n_p_q1skip6  n_p_q1skip6,0,<,n_p_q1skip6  n_p_q1skip6, ,<,n_p_q1skip7
n_p_q1skip7,1,<,n_p_q1skip7 n_p_q1skip7,0,<,n_p_q1skip7
			n_p_q1skip7, ,>,n_p_q1skip8
			n_p_q1skip8,1,<,n_p_q1skip9  n_p_q1skip8,0,<,n_p_q1skip9 //
				n_p_q1skip9,1, ,n_p1q1put
				n_p_q1skip9,0, ,n_p0q1put
				n_p_q1skip9, , ,n_p_q1put
// 18
n_p_q0res,0,0,n_p_q0skip  n_p_q0res,1,1,n_p_q0skip 
	n_p_q0skip, ,<,n_p_q0skip1 n_p_q0skip,1,<,n_p_q0skip  n_p_q0skip,0,<,n_p_q0skip
	n_p_q0skip1,1,<,n_p_q0skip1 n_p_q0skip1,0,<,n_p_q0skip1  n_p_q0skip1, , ,n_p_q0skip2  
	n_p_q0skip2,1,<,n_p_q0skip2  n_p_q0skip2,0,<,n_p_q0skip2  
	n_p_q0skip2, ,>,n_p_q0skip3 //
	n_p_q0skip3,1,<,n_p_q0skip4  n_p_q0skip3,0,<,n_p_q0skip4
		n_p_q0skip4,1, ,n1p_q0skip5 //?
			n1p_q0skip5, ,<,n1p_q0skip6
			n1p_q0skip6,1,<,n1p_q0skip6  n1p_q0skip6,0,<,n1p_q0skip6  n1p_q0skip6, ,<,n1p_q0skip7
n1p_q0skip7,1,<,n1p_q0skip7 n1p_q0skip7,0,<,n1p_q0skip7
			n1p_q0skip7, ,>,n1p_q0skip8
			n1p_q0skip8,1,<,n1p_q0skip9  n1p_q0skip8,0,<,n1p_q0skip9 //
				n1p_q0skip9,1, ,n1p1q0put
				n1p_q0skip9,0, ,n1p0q0put
				n1p_q0skip9, , ,n1p_q0put
		n_p_q0skip4,0, ,n0p_q0skip5 //?
			n0p_q0skip5, ,<,n0p_q0skip6
			n0p_q0skip6,1,<,n0p_q0skip6  n0p_q0skip6,0,<,n0p_q0skip6  n0p_q0skip6, ,<,n0p_q0skip7
n0p_q0skip7,1,<,n0p_q0skip7 n0p_q0skip7,0,<,n0p_q0skip7
			n0p_q0skip7, ,>,n0p_q0skip8
			n0p_q0skip8,1,<,n0p_q0skip9  n0p_q0skip8,0,<,n0p_q0skip9 //
				n0p_q0skip9,1, ,n0p1q0put
				n0p_q0skip9,0, ,n0p0q0put
				n0p_q0skip9, , ,n0p_q0put
		n_p_q0skip4, , ,n_p_q0skip5 //?
			n_p_q0skip5, ,>,n_p_q0skip6
			n_p_q0skip6,1,<,n_p_q0skip6  n_p_q0skip6,0,<,n_p_q0skip6  n_p_q0skip6, ,<,n_p_q0skip7
n_p_q0skip7,1,<,n_p_q0skip7 n_p_q0skip7,0,<,n_p_q0skip7
			n_p_q0skip7, ,>,n_p_q0skip8
			n_p_q0skip8,1,<,n_p_q0skip9  n_p_q0skip8,0,<,n_p_q0skip9 //
				n_p_q0skip9,1, ,n_p1q0put
				n_p_q0skip9,0, ,n_p0q0put
				n_p_q0skip9, , ,n_p_q0put
// функции put
n1p1q0put, ,>,n1p1q0put1
	n1p1q0put1,1,>,n1p1q0put1  n1p1q0put1,0,>,n1p1q0put1  n1p1q0put1, ,>,n1p1q0put2
	n1p1q0put2,1,>,n1p1q0put2  n1p1q0put2,0,>,n1p1q0put2  n1p1q0put2, ,>,n1p1q0put3
	n1p1q0put3,1,>,n1p1q0put3  n1p1q0put3,0,>,n1p1q0put3  n1p1q0put3, ,>,n1p1q0put4
	n1p1q0put4,1,>,n1p1q0put4  n1p1q0put4,0,>,n1p1q0put4  n1p1q0put4, ,0,n1p1q1res
n1p1q1put, ,>,n1p1q1put1
	n1p1q1put1,1,>,n1p1q1put1  n1p1q1put1,0,>,n1p1q1put1  n1p1q1put1, ,>,n1p1q1put2
	n1p1q1put2,1,>,n1p1q1put2  n1p1q1put2,0,>,n1p1q1put2  n1p1q1put2, ,>,n1p1q1put3
	n1p1q1put3,1,>,n1p1q1put3  n1p1q1put3,0,>,n1p1q1put3  n1p1q1put3, ,>,n1p1q1put4
	n1p1q1put4,1,>,n1p1q1put4  n1p1q1put4,0,>,n1p1q1put4  n1p1q1put4, ,1,n1p1q1res
n1p0q0put, ,>,n1p0q0put1
	n1p0q0put1,1,>,n1p0q0put1  n1p0q0put1,0,>,n1p0q0put1  n1p0q0put1, ,>,n1p0q0put2
	n1p0q0put2,1,>,n1p0q0put2  n1p0q0put2,0,>,n1p0q0put2  n1p0q0put2, ,>,n1p0q0put3
	n1p0q0put3,1,>,n1p0q0put3  n1p0q0put3,0,>,n1p0q0put3  n1p0q0put3, ,>,n1p0q0put4
	n1p0q0put4,1,>,n1p0q0put4  n1p0q0put4,0,>,n1p0q0put4  n1p0q0put4, ,1,n1p0q0res
n1p0q1put, ,>,n1p0q1put1
	n1p0q1put1,1,>,n1p0q1put1  n1p0q1put1,0,>,n1p0q1put1  n1p0q1put1, ,>,n1p0q1put2
	n1p0q1put2,1,>,n1p0q1put2  n1p0q1put2,0,>,n1p0q1put2  n1p0q1put2, ,>,n1p0q1put3
	n1p0q1put3,1,>,n1p0q1put3  n1p0q1put3,0,>,n1p0q1put3  n1p0q1put3, ,>,n1p0q1put4
	n1p0q1put4,1,>,n1p0q1put4  n1p0q1put4,0,>,n1p0q1put4  n1p0q1put4, ,0,n1p0q1res
n0p1q0put, ,>,n0p1q0put1
	n0p1q0put1,1,>,n0p1q0put1  n0p1q0put1,0,>,n0p1q0put1  n0p1q0put1, ,>,n0p1q0put2
	n0p1q0put2,1,>,n0p1q0put2  n0p1q0put2,0,>,n0p1q0put2  n0p1q0put2, ,>,n0p1q0put3
	n0p1q0put3,1,>,n0p1q0put3  n0p1q0put3,0,>,n0p1q0put3  n0p1q0put3, ,>,n0p1q0put4
	n0p1q0put4,1,>,n0p1q0put4  n0p1q0put4,0,>,n0p1q0put4  n0p1q0put4, ,1,n0p1q0res
n0p1q1put, ,>,n0p1q1put1
	n0p1q1put1,1,>,n0p1q1put1  n0p1q1put1,0,>,n0p1q1put1  n0p1q1put1, ,>,n0p1q1put2
	n0p1q1put2,1,>,n0p1q1put2  n0p1q1put2,0,>,n0p1q1put2  n0p1q1put2, ,>,n0p1q1put3
	n0p1q1put3,1,>,n0p1q1put3  n0p1q1put3,0,>,n0p1q1put3  n0p1q1put3, ,>,n0p1q1put4
	n0p1q1put4,1,>,n0p1q1put4  n0p1q1put4,0,>,n0p1q1put4  n0p1q1put4, ,0,n0p1q0res
n0p0q0put, ,>,n0p0q0put1
	n0p0q0put1,1,>,n0p0q0put1  n0p0q0put1,0,>,n0p0q0put1  n0p0q0put1, ,>,n0p0q0put2
	n0p0q0put2,1,>,n0p0q0put2  n0p0q0put2,0,>,n0p0q0put2  n0p0q0put2, ,>,n0p0q0put3
	n0p0q0put3,1,>,n0p0q0put3  n0p0q0put3,0,>,n0p0q0put3  n0p0q0put3, ,>,n0p0q0put4
	n0p0q0put4,1,>,n0p0q0put4  n0p0q0put4,0,>,n0p0q0put4  n0p0q0put4, ,0,n0p0q0res
n0p0q1put, ,>,n0p0q1put1
	n0p0q1put1,1,>,n0p0q1put1  n0p0q1put1,0,>,n0p0q1put1  n0p0q1put1, ,>,n0p0q1put2
	n0p0q1put2,1,>,n0p0q1put2  n0p0q1put2,0,>,n0p0q1put2  n0p0q1put2, ,>,n0p0q1put3
	n0p0q1put3,1,>,n0p0q1put3  n0p0q1put3,0,>,n0p0q1put3  n0p0q1put3, ,>,n0p0q1put4
	n0p0q1put4,1,>,n0p0q1put4  n0p0q1put4,0,>,n0p0q1put4  n0p0q1put4, ,1,n0p0q0res
n_p1q1put, ,>,n_p1q1put1
	n_p1q1put1,1,>,n_p1q1put1  n_p1q1put1,0,>,n_p1q1put1  n_p1q1put1, ,>,n_p1q1put2
	n_p1q1put2,1,>,n_p1q1put2  n_p1q1put2,0,>,n_p1q1put2  n_p1q1put2, ,>,n_p1q1put3
	n_p1q1put3,1,>,n_p1q1put3  n_p1q1put3,0,>,n_p1q1put3  n_p1q1put3, , ,n_p1q1put4
	n_p1q1put4,1,>,n_p1q1put4  n_p1q1put4,0,>,n_p1q1put4  n_p1q1put4, ,0,n_p1q0res
n_p1q0put, ,>,n_p1q0put1
	n_p1q0put1,1,>,n_p1q0put1  n_p1q0put1,0,>,n_p1q0put1  n_p1q0put1, ,>,n_p1q0put2
	n_p1q0put2,1,>,n_p1q0put2  n_p1q0put2,0,>,n_p1q0put2  n_p1q0put2, ,>,n_p1q0put3
	n_p1q0put3,1,>,n_p1q0put3  n_p1q0put3,0,>,n_p1q0put3  n_p1q0put3, , ,n_p1q0put4
	n_p1q0put4,1,>,n_p1q0put4  n_p1q0put4,0,>,n_p1q0put4  n_p1q0put4, ,1,n_p1q0res
n_p0q1put, ,>,n_p0q1put1
	n_p0q1put1,1,>,n_p0q1put1  n_p0q1put1,0,>,n_p0q1put1  n_p0q1put1, ,>,n_p0q1put2
	n_p0q1put2,1,>,n_p0q1put2  n_p0q1put2,0,>,n_p0q1put2  n_p0q1put2, ,>,n_p0q1put3
	n_p0q1put3,1,>,n_p0q1put3  n_p0q1put3,0,>,n_p0q1put3  n_p0q1put3, , ,n_p0q1put4
	n_p0q1put4,1,>,n_p0q1put4  n_p0q1put4,0,>,n_p0q1put4  n_p0q1put4, ,1,n_p0q0res
n_p0q0put, ,>,n_p0q0put1
	n_p0q0put1,1,>,n_p0q0put1  n_p0q0put1,0,>,n_p0q0put1  n_p0q0put1, ,>,n_p0q0put2
	n_p0q0put2,1,>,n_p0q0put2  n_p0q0put2,0,>,n_p0q0put2  n_p0q0put2, ,>,n_p0q0put3
	n_p0q0put3,1,>,n_p0q0put3  n_p0q0put3,0,>,n_p0q0put3  n_p0q0put3, , ,n_p0q0put4
	n_p0q0put4,1,>,n_p0q0put4  n_p0q0put4,0,>,n_p0q0put4  n_p0q0put4, ,0,n_p0q0res
n1p_q1put, ,>,n1p_q1put1
	n1p_q1put1,1,>,n1p_q1put1  n1p_q1put1,0,>,n1p_q1put1  n1p_q1put1, ,>,n1p_q1put2
	n1p_q1put2,1,>,n1p_q1put2  n1p_q1put2,0,>,n1p_q1put2  n1p_q1put2, ,>,n1p_q1put3
	n1p_q1put3,1,>,n1p_q1put3  n1p_q1put3,0,>,n1p_q1put3  n1p_q1put3, ,>,n1p_q1put4
	n1p_q1put4,1,>,n1p_q1put4  n1p_q1put4,0,>,n1p_q1put4  n1p_q1put4, ,0,n1p_q0res
n1p_q0put, ,>,n1p_q0put1
	n1p_q0put1,1,>,n1p_q0put1  n1p_q0put1,0,>,n1p_q0put1  n1p_q0put1, ,>,n1p_q0put2
	n1p_q0put2,1,>,n1p_q0put2  n1p_q0put2,0,>,n1p_q0put2  n1p_q0put2, ,>,n1p_q0put3
	n1p_q0put3,1,>,n1p_q0put3  n1p_q0put3,0,>,n1p_q0put3  n1p_q0put3, ,>,n1p_q0put4
	n1p_q0put4,1,>,n1p_q0put4  n1p_q0put4,0,>,n1p_q0put4  n1p_q0put4, ,1,n1p_q0res
n0p_q1put, ,>,n0p_q1put1
	n0p_q1put1,1,>,n0p_q1put1  n0p_q1put1,0,>,n0p_q1put1  n0p_q1put1, ,>,n0p_q1put2
	n0p_q1put2,1,>,n0p_q1put2  n0p_q1put2,0,>,n0p_q1put2  n0p_q1put2, ,>,n0p_q1put3
	n0p_q1put3,1,>,n0p_q1put3  n0p_q1put3,0,>,n0p_q1put3  n0p_q1put3, ,>,n0p_q1put4
	n0p_q1put4,1,>,n0p_q1put4  n0p_q1put4,0,>,n0p_q1put4  n0p_q1put4, ,1,n0p_q0res
n0p_q0put, ,>,n0p_q0put1
	n0p_q0put1,1,>,n0p_q0put1  n0p_q0put1,0,>,n0p_q0put1  n0p_q0put1, ,>,n0p_q0put2
	n0p_q0put2,1,>,n0p_q0put2  n0p_q0put2,0,>,n0p_q0put2  n0p_q0put2, ,>,n0p_q0put3
	n0p_q0put3,1,>,n0p_q0put3  n0p_q0put3,0,>,n0p_q0put3  n0p_q0put3, ,>,n0p_q0put4
	n0p_q0put4,1,>,n0p_q0put4  n0p_q0put4,0,>,n0p_q0put4  n0p_q0put4, ,0,n0p_q0res
n_p_q1put, ,>,n_p_q1put1
	n_p_q1put1,1,>,n_p_q1put1  n_p_q1put1,0,>,n_p_q1put1  n_p_q1put1, ,>,n_p_q1put2
	n_p_q1put2,1,>,n_p_q1put2  n_p_q1put2,0,>,n_p_q1put2  n_p_q1put2, ,>,n_p_q1put3
	n_p_q1put3,1,>,n_p_q1put3  n_p_q1put3,0,>,n_p_q1put3  n_p_q1put3, ,1,n_p_q1put4
	n_p_q1put4,1,>,n_p_q1put4  n_p_q1put4,0,>,n_p_q1put4  n_p_q1put4, ,<,exit
n_p_q0put, ,>,n_p_q0put1
	n_p_q0put1,1,>,n_p_q0put1  n_p_q0put1,0,>,n_p_q0put1  n_p_q0put1, ,>,n_p_q0put2
	n_p_q0put2,1,>,n_p_q0put2  n_p_q0put2,0,>,n_p_q0put2  n_p_q0put2, ,>,n_p_q0put3
	n_p_q0put3,1,>,n_p_q0put3  n_p_q0put3,0,>,n_p_q0put3  n_p_q0put3, ,>,n_p_q0put4
	n_p_q0put4,1,>,n_p_q0put4  n_p_q0put4,0,>,n_p_q0put4  n_p_q0put4, ,<,exit
exit,1,>,exit_ exit,0,>,exit_  exit, ,<,exit2  
exit2,1,>,exit20  exit2,0,>,exit20  exit20, , ,exit_
exit_, , ,nu
//минус нули
nu, ,<,nu1
nu1,0,<,nuch  
	nuch,1,>,nud1  
		nud1,0, ,rea
	nuch,0,>,nud0
		nud0,0, ,nu
        nuch, ,>,stop_
nu1,1,>,rea
//переворот в рот
rea, ,<,rea1ch
rea1ch,1,<,rea1ch1
rea1ch1, ,>,rea1ch3
rea1ch3,1,>,stop_
rea1ch1,1,>,rea1
rea1ch1,0,>,rea1
rea1,1, ,a1skip
	a1skip, ,<,a1skip1  
	a1skip1,1,<,a1skip1  a1skip1,0,<,a1skip1  a1skip1, ,>,a1skip2
	a1skip2,1, ,a1b1
	a1skip2,0, ,a1b0
// 1
a1b1, , ,a1b1r
	a1b1r, ,>,a1b1check
	a1b1check, ,1,a1b1check1  //print b
		a1b1check1,1,<,a1b1check1  a1b1check1,0,<,a1b1check1
			a1b1check1, ,1,leave  //print a
	a1b1check,1,>,a1b1check2
	a1b1check,0,>,a1b1check2
	a1b1check2, ,1,a1b1check3  // print b
		a1b1check3,1,<,a1b1check3  a1b1check3,0,<,a1b1check3
			a1b1check3, ,1,leave  // print a
	a1b1check2,1,<,a1b1check4  a1b1check2,0,<,a1b1check4
		a1b1check4,1,<,a1b1check4  a1b1check4,0,<,a1b1check4
			a1b1check4, , ,a1b1r_
	a1b1r_, ,>,a1b1r1
	a1b1r1,1,>,a1b1r1  a1b1r1,0,>,a1b1r1
	a1b1r1, ,1,a1b1l  // print b
	a1b1l,1,<,a1b1l1  a1b1l,0,<,a1b1l1
	a1b1l1,1, ,a1b1l2  // get new a
		a1b1l2, ,<,a1b1l3
		a1b1l3,1,<,a1b1l3  a1b1l3,0,<,a1b1l3		
		a1b1l3, ,1,a1b1l4 // print a	
		a1b1l4,1,>,a1b1l5  a1b1l4,0,>,a1b1l5
		a1b1l5,1, ,a1b1 // get new b
		a1b1l5,0, ,a1b0
	a1b1l1,0, ,a0b1l2 // get new a
		a0b1l2, ,<,a0b1l3
		a0b1l3,1,<,a0b1l3  a0b1l3,0,<,a0b1l3
		a0b1l3, ,1,a0b1l4 // print a
		a0b1l4,1,>,a0b1l5  a0b1l4,0,>,a1b1l5
		a0b1l5,1, ,a0b1 // get new b
		a0b1l5,0, ,a0b0
// 2
a1b0, , ,a1b0r
	a1b0r, ,>,a1b0check
	a1b0check, ,0,a1b0check1  //print b
		a1b0check1,1,<,a1b0check1  a1b0check1,0,<,a1b0check1
			a1b0check1, ,1,leave  //print a
	a1b0check,1,>,a1b0check2
	a1b0check,0,>,a1b0check2
	a1b0check2, ,0,a1b0check3 // print b
		a1b0check3,1,<,a1b0check3  a1b0check3,0,<,a1b0check3
			a1b0check3, ,1,leave  // print a
	a1b0check2,1,<,a1b0check4  a1b0check2,0,<,a1b0check4
		a1b0check4,1,<,a1b0check4  a1b0check4,0,<,a1b0check4
			a1b0check4, , ,a1b0r_
	a1b0r_, ,>,a1b0r1
	a1b0r1,1,>,a1b0r1  a1b0r1,0,>,a1b0r1
	a1b0r1, ,0,a1b0l  // print b
	a1b0l,1,<,a1b0l1  a1b0l,0,<,a1b0l1
	a1b0l1,1, ,a1b0l2  // get new a
		a1b0l2, ,<,a1b0l3
		a1b0l3,1,<,a1b0l3  a1b0l3,0,<,a1b0l3	
		a1b0l3, ,1,a1b0l4 // print a	
		a1b0l4,1,>,a1b0l5  a1b0l4,0,>,a1b0l5
		a1b0l5,1, ,a1b1 // get new b
		a1b0l5,0, ,a1b0
	a1b0l1,0, ,a0b0l2 // get new a
		a0b0l2, ,<,a0b0l3
		a0b0l3,1,<,a0b0l3  a0b0l3,0,<,a0b0l3	
		a0b0l3, ,1,a0b0l4 // print a	
		a0b0l4,1,>,a0b0l5  a0b0l4,0,>,a1b0l5
		a0b0l5,1, ,a0b1 // get new b
		a0b0l5,0, ,a0b0
// 3
a0b1, , ,a0b1r
	a0b1r, ,>,a0b1check	
	a0b1check, ,1,a0b1check1  //print b
		a0b1check1,1,<,a0b1check1  a0b1check1,0,<,a0b1check1
			a0b1check1, ,0,leave  //print a
	a0b1check,1,>,a0b1check2
	a0b1check,0,>,a0b1check2	
	a0b1check2, ,1,a0b1check3 // print b
		a0b1check3,1,<,a0b1check3  a0b1check3,0,<,a0b1check3
			a0b1check3, ,0,leave  // print a
	a0b1check2,1,<,a0b1check4  a0b1check2,0,<,a0b1check4
		a0b1check4,1,<,a0b1check4  a0b1check4,0,<,a0b1check4
			a0b1check4, , ,a0b1r_
	a0b1r_, ,>,a0b1r1
	a0b1r1,1,>,a0b1r1  a0b1r1,0,>,a0b1r1
	a0b1r1, ,1,a0b1l  // print b
	a0b1l,1,<,a0b1l1  a0b1l,0,<,a0b1l1
	a0b1l1,1, ,a1b1l2  // get new a
	a0b1l1,0, ,a0b1l2  // get new a
// 4		
a0b0, , ,a0b0r
	a0b0r, ,>,a0b0check
	a0b0check, ,0,a0b0check1  //print b
		a0b0check1,1,<,a0b0check1  a0b0check1,0,<,a0b0check1
			a0b0check1, ,0,leave  //print a
	a0b0check,1,>,a0b0check2
	a0b0check,0,>,a0b0check2	
	a0b0check2, ,0,a0b0check3  // print b
		a0b0check3,1,<,a0b0check3  a0b0check3,0,<,a0b0check3
			a0b0check3, ,0,leave  // print a
	a0b0check2,1,<,a0b0check4  a0b0check2,0,<,a0b0check4
		a0b0check4,1,<,a0b0check4  a0b0check4,0,<,a0b0check4
			a0b0check4, , ,a0b0r_
	a0b0r_, ,>,a0b0r1
	a0b0r1,1,>,a0b0r1  a0b0r1,0,>,a0b0r1
	a0b0r1, ,0,a0b0l  // print b
	a0b0l,1,<,a0b0l1  a0b0l,0,<,a0b0l1
	a0b0l1,1, ,a1b0l2  // get new a
	a0b0l1,0, ,a0b0l2  // get new a
// leave
leave,1,>,stop_
leave,0,>,stop_
// stop
stop_,1,>,stop_  stop_,0,>,stop_  stop_, , ,stop_