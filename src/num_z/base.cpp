#include "../include/num_z.h"
#include <string>

num_z hex(const num_z &a){
	num_z res(a);
	res._base_repr = HEX;
	return res;
}

num_z bin(const num_z &a){
	num_z res(a);
	res._base_repr = BIN;
	return res;
}

std::string hex_f(const num_z &a){
	uint32_t max32 = 0x80000000;
	uint64_t base_32;
	char *output;
	int n_chars = a._sign;
	num_z aux(0);
	mod_tuple aux2;
	std::string out;
	
	if(a == 0){
		return std::string("0x0");
	}
	
	aux2.q = a;
	aux2.q._sign = 0;
	
	aux.__resize(a._blocks + 1);
	
	
	base_32 = uint64_t(max32) << 1;
	max32 = 0;
	
	while(aux2.q != 0){ 
		aux2 = aux2.q % base_32;
		aux._num[max32] = (aux2.r._num[1]*_BASE_ + aux2.r._num[0]);
		++max32;
	}
	
	while(aux._num[max32 - 1] == 0 && (max32 ^ 1)) --max32;
	
	output = (char *)malloc(8*max32 + a._sign + 1);
	
	if(a._sign) sprintf(output, "-");
	n_chars += sprintf(output + n_chars, "0x%x", aux._num[--max32]);
	while(max32--) n_chars += sprintf(output + n_chars, "%08x", aux._num[max32]);
	
	out = std::string(output);
	free(output);	
	
	return out;
}

std::string bin_f(const num_z &a){
	uint32_t max32 = 0x80000000;
	int64_t blocks;
	uint64_t base_32;
	num_z aux(0);
	mod_tuple aux2;
	std::string out("");
	if(a == 0){
		printf("0b0");
		return std::string("0b0");
	}
	
	aux2.q = a;
	aux2.q._sign = 0;
	
	aux.__resize(a._blocks + 1);
	
	base_32 = uint64_t(max32) << 1;
	max32 = 0;
	while(aux2.q != 0){ 
		aux2 = aux2.q % base_32;
		aux._num[max32++] = (aux2.r._num[1]*_BASE_ + aux2.r._num[0]);
	}
	
	while(aux._num[max32 - 1] == 0 && (max32 ^ 1)) --max32;
	
	blocks = max32 - 1;
	
	if(a._sign) out += "-";
	out += "0b";
	
	max32 = 1 << 31;
	while(!(max32 & aux._num[blocks]) && max32){
		max32 >>= 1;
	}
	
	while(max32){
		out += std::to_string(int((max32 & aux._num[blocks]) > 0));
		max32 >>= 1;
	}
	while(blocks--){
		max32 = 1 << 31;
		while(max32){
			out += std::to_string(int((max32 & aux._num[blocks]) > 0));
			max32 >>= 1;
		}
	}
	
	return out;
}
