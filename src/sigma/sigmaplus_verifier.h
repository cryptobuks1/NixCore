#ifndef SIGMA_SIGMAPLUS_VERIFIER_H
#define SIGMA_SIGMAPLUS_VERIFIER_H

#include <sigma/r1_proof_verifier.h>
#include <sigma/sigmaplus_proof.h>
#include <sigma/sigma_primitives.h>
#include <secp256k1/include/MultiExponent.h>
#include <util.h>

namespace sigma {
template<class Exponent, class GroupElement>
class SigmaPlusVerifier{

public:
    SigmaPlusVerifier(const GroupElement& g,
                      const std::vector<GroupElement>& h_gens,
                      int n, int m_);

    bool verify(const std::vector<GroupElement>& commits,
                const SigmaPlusProof<Exponent, GroupElement>& proof,
                bool fPadding) const;

private:
    GroupElement g_;
    std::vector<GroupElement> h_;
    int n;
    int m;
};

} // namespace sigma

#include <sigma/sigmaplus_verifier.hpp>

#endif // SIGMA_SIGMAPLUS_VERIFIER_H
