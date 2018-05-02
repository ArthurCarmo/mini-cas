#include "../include/num_z.h"

num_z num_z::_long_mul(uint64_t a, uint64_t b){
	num_z res, parc1;
/*	uint64_t ops[2][3] = { {a%_BLOCK_HALF_LAST_, (a%_BLOCK_LAST_64_)/_BLOCK_HALF_LAST_, a/_BLOCK_LAST_64_},
						   {b%_BLOCK_HALF_LAST_, (b%_BLOCK_LAST_64_)/_BLOCK_HALF_LAST_, b/_BLOCK_LAST_64_}};
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			parc1 = ops[0][i] * ops[1][j];
			if((parc1 != 0) && (i+j) > 0)
				parc1.__left_shift((i+j) * 9);
			res += parc1;
		}
	} */
	return res;
}


uint64_t num_z::_mod_b(){
	return this->_num[0];
}

uint64_t num_z::_div_b(){
	return (this->_blocks>1)?this->_num[1]:0;
}
