#ifndef _CHROMOSOME_H_
#define _CHROMOSOME_H_

#include "GenomeSequence.h"

class Chromosome{
public:
    Chromosome(GenomeSequence* gs, uint chrosomeIndex);
    Chromosome(GenomeSequence* gs, const char* chromosomeName);
    Chromosome(const char* genomseSequenceFileName, uint chromosomeIndex, bool isColorSpace);
    Chromosome(const std::string& genomseSequenceFileName, uint chromosomeIndex, bool isColorSpace);
    genomeIndex_t Length() const
    {
        return chromosomeSize;
    }
    // 0-based index 
    inline char operator[](genomeIndex_t index) const
    {
        index += offset;
        return (*gs)[index];
    }
    const char* Name() const {
        return (*gs);
    }
private:
    GenomeSequence* gs;
    int chromosomeIndex;
    genomeIndex_t offset;           // chromosome index 0 corresponds (*gs)[offset]
    genomeIndex_t chromosomeSize;   // return the length of the chromosome
};

#endif /* _CHROMOSOME_H_ */
