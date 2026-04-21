---
title: quantum_computing (11)
date: 2026-04-21T19:40:49+08:00
lastmod: 2026-04-21T20:15:00+08:00
---

# quantum_computing (11)

## 1 Postulates of Quantum Mechanics

> 💡 **Recall (Quantum Foundations):** A Hermitian operator has a spectral decomposition, pure states are rays, and measurement probabilities come from projecting onto eigenspaces.

### States

Any quantum system is described by a finite-dimensional Hilbert space $\mathcal{H}$.

A pure state is a normalized vector $|\Psi\rangle \in \mathcal{H}$ with $\lVert \Psi \rVert = 1$.

Physical pure states are rays:

$|\Psi\rangle \sim e^{if}|\Psi\rangle$

since global phase does not affect probabilities.

### Observables

An observable is a Hermitian operator $F : \mathcal{H} \to \mathcal{H}$ with spectral decomposition

$$
F = \sum_{\lambda \in \sigma(F)} \lambda P_\lambda
$$

where $P_\lambda$ is the orthogonal projector onto the eigenspace for $\lambda$.

### Measurement

If the system is in state $|\Psi\rangle$, then

$$
\mathbb{P}_{\Psi}(\lambda) = \langle \Psi | P_\lambda | \Psi \rangle = \lVert P_\lambda |\Psi\rangle \rVert^2
$$

and

$$
\sum_{\lambda \in \sigma(F)} \mathbb{P}_{\Psi}(\lambda) = 1.
$$

Expected value:

$$
\langle F \rangle_\Psi = \langle \Psi | F | \Psi \rangle = \sum_{\lambda \in \sigma(F)} \lambda \, \mathbb{P}_{\Psi}(\lambda).
$$

Post-measurement state after outcome $\lambda$:

$$
|\varphi\rangle = \frac{P_\lambda |\Psi\rangle}{\lVert P_\lambda |\Psi\rangle \rVert}.
$$

### Probability-space point of view

Measurement of $F$ on $|\Psi\rangle$ defines

$$
(\sigma(F), 2^{\sigma(F)}, \mathbb{P}_\Psi).
$$

### Uncertainty

For an observable $F$ in state $|\Psi\rangle$,

$$
\Delta_\Psi(F) = \sqrt{\langle (F - \langle F \rangle_\Psi I)^2 \rangle_\Psi}.
$$

Also

$$
\Delta_\Psi^2(F) = \langle F^2 \rangle_\Psi - \langle F \rangle_\Psi^2.
$$

Fact:

$$
\Delta_\Psi(F) = 0 \iff F|\Psi\rangle = \lambda |\Psi\rangle
$$

for some $\lambda \in \sigma(F)$.

### Compatible observables

Observables $F,G$ are compatible iff

$$
[F,G] := FG - GF = 0.
$$

If $[F,G]=0$, then $F$ and $G$ are simultaneously diagonalizable.

### Robertson-Schrödinger uncertainty relation

Let

$$
\hat{F} = F - \langle F \rangle_\Psi I, \qquad \hat{G} = G - \langle G \rangle_\Psi I.
$$

Then

$$
\Delta_\Psi^2(F)\Delta_\Psi^2(G) \ge \frac{1}{4}\langle \{\hat{F},\hat{G}\} \rangle_\Psi^2 + \frac{1}{4}\left|\langle [F,G] \rangle_\Psi\right|^2.
$$

Quantum covariance:

$$
\operatorname{Cov}_Q(F,G) = \frac{1}{2}\langle \{\hat{F},\hat{G}\} \rangle_\Psi.
$$

Hence

$$
\Delta_\Psi^2(F)\Delta_\Psi^2(G) \ge \operatorname{Cov}_Q(F,G)^2 + \frac{1}{4}\left|\langle [F,G] \rangle_\Psi\right|^2.
$$

## 2 Time Evolution

> 💡 **Recall (Quantum Foundations):** Unitary operators preserve inner products and norms, so closed-system evolution must be unitary.

### Schrödinger evolution

For a closed system,

$$
|\Psi(t)\rangle = U(t,t_0)|\Psi(t_0)\rangle
$$

where

$$
i\frac{d}{dt}U(t,t_0) = H(t)U(t,t_0), \qquad U(t_0,t_0)=I.
$$

Equivalently,

$$
i\frac{d}{dt}|\Psi(t)\rangle = H(t)|\Psi(t)\rangle.
$$

Here $H(t)$ is the Hamiltonian, hence Hermitian.

### Unitarity

If $H(t)^\dagger = H(t)$, then

$$
U(t,t_0)^\dagger U(t,t_0) = I.
$$

So closed-system evolution preserves normalization.

### Time-independent Hamiltonian

If $H$ does not depend on time and $t_0=0$, then

$$
U(t)=e^{-itH}, \qquad |\Psi(t)\rangle = e^{-itH}|\Psi_0\rangle.
$$

If

$$
H=\sum_i E_i P_{E_i},
$$

then

$$
e^{-itH}=\sum_i e^{-itE_i}P_{E_i}
$$

and

$$
|\Psi(t)\rangle = \sum_i e^{-itE_i}P_{E_i}|\Psi_0\rangle.
$$

If $|\Psi_0\rangle$ is an energy eigenstate with eigenvalue $E_k$, then

$$
|\Psi(t)\rangle = e^{-itE_k}|\Psi_0\rangle,
$$

so only a global phase is acquired.

### Stone theorem

If $U(t)$ is a continuous one-parameter unitary group with $U(0)=I$ and $U(t+s)=U(t)U(s)$, then

$$
U(t)=e^{-itH}
$$

for a unique Hermitian $H$.

## 3 Mixed States

> 💡 **Recall (Quantum Foundations):** A quantum state is a positive operator with unit trace; pure states are rank-1 projectors and mixed states are convex combinations of them.

### Density operator

If the preparation is probabilistic and the system is in $|\Psi_k\rangle$ with probability $p_k$, define

$$
\rho = \sum_k p_k |\Psi_k\rangle\langle\Psi_k|.
$$

This is the density operator of the ensemble.

### Measurement on mixed states

For an observable $F=\sum_\lambda \lambda P_\lambda$,

$$
\mathbb{P}_\rho(\lambda)=\operatorname{tr}(\rho P_\lambda),
$$

and

$$
\langle F \rangle_\rho = \operatorname{tr}(\rho F).
$$

If outcome $\lambda$ is obtained, then

$$
\rho \longmapsto \rho_\lambda = \frac{P_\lambda \rho P_\lambda}{\operatorname{tr}(P_\lambda \rho)}.
$$

If the measurement is performed but the outcome is forgotten, then

$$
\rho \longmapsto \sum_{\lambda \in \sigma(F)} P_\lambda \rho P_\lambda.
$$

### Basic properties

For every density matrix $\rho$:

1. $\rho \ge 0$
2. $\operatorname{tr}(\rho)=1$

Conversely, every operator satisfying these two conditions is a valid state.

By spectral decomposition,

$$
\rho = \sum_{k=1}^d \lambda_k |e_k\rangle\langle e_k|
$$

with $\lambda_k \ge 0$ and $\sum_k \lambda_k = 1$.

### Convexity

If $\rho_1,\dots,\rho_n$ are density matrices and $p_k \ge 0$, $\sum_k p_k=1$, then

$$
\rho = \sum_{k=1}^n p_k \rho_k
$$

is again a density matrix.

### Pure states

Pure states are exactly rank-$1$ projectors:

$$
\rho = |\Psi\rangle\langle\Psi|.
$$

Equivalent characterization:

$$
\rho \text{ pure } \iff \operatorname{tr}(\rho^2)=\operatorname{tr}(\rho)=1.
$$

### Many ensembles for the same $\rho$

The same $\rho$ can have many decompositions

$$
\rho = \sum_i p_i |\psi_i\rangle\langle\psi_i|.
$$

If

$$
\rho=\sum_{k=1}^n \lambda_k |e_k\rangle\langle e_k|
$$

is the spectral decomposition, then

$$
\rho = \sum_{i=1}^m p_i |\psi_i\rangle\langle\psi_i|
$$

iff $m \ge n$ and there exists $U \in \mathcal{U}(m)$ such that

$$
\sqrt{p_i}|\psi_i\rangle = \sum_{j=1}^n U_{ij}\sqrt{\lambda_j}|e_j\rangle.
$$

### Entropy

von Neumann entropy:

$$
S(\rho) = -\operatorname{tr}(\rho \log \rho) = -\sum_k \lambda_k \log \lambda_k.
$$

Facts:

$$
S(\rho)=0 \iff \rho \text{ is pure}
$$

and for the maximally mixed state $\rho_M = \frac{1}{d}I$,

$$
S(\rho_M)=\log d.
$$

### Unitary evolution of mixed states

If the closed system evolves by $U(t,t_0)$, then

$$
\rho(t)=U(t,t_0)\rho(t_0)U(t,t_0)^\dagger.
$$

## 4 Composite Systems and Partial Trace

> 💡 **Recall (Quantum Foundations):** The state of a subsystem is the unique density matrix reproducing all expectation values of observables acting only on that subsystem.

### Composite Hilbert space

For distinguishable systems,

$$
\mathcal{H}=\mathcal{H}_1 \otimes \cdots \otimes \mathcal{H}_N.
$$

For indistinguishable systems:

1. Fermionic: $\mathcal{H}=\bigwedge^N \mathbb{C}^d$
2. Bosonic: $\mathcal{H}=\bigvee^N \mathbb{C}^d$

We focus mainly on the distinguishable case.

### Observables of subsystems

For a bipartite system $\mathcal{H}_1 \otimes \mathcal{H}_2$:

$$
F_1 \mapsto F_1 \otimes I, \qquad F_2 \mapsto I \otimes F_2.
$$

Reduced states $\rho^{(1)}$, $\rho^{(2)}$ are defined by

$$
\operatorname{tr}(\rho^{(1)}F_1)=\langle \Psi|F_1 \otimes I|\Psi\rangle,
$$

$$
\operatorname{tr}(\rho^{(2)}F_2)=\langle \Psi|I \otimes F_2|\Psi\rangle.
$$

### Bipartite pure state

Let

$$
|\Psi\rangle=\sum_{i=1}^{d_1}\sum_{j=1}^{d_2} C_{ij}|e_i\rangle \otimes |f_j\rangle.
$$

Then

$$
\rho^{(1)}=\operatorname{tr}_2(|\Psi\rangle\langle\Psi|)=CC^\dagger,
$$

$$
\rho^{(2)}=\operatorname{tr}_1(|\Psi\rangle\langle\Psi|)=C^T\overline{C}.
$$

If $|\Psi\rangle=|\psi_1\rangle\otimes|\psi_2\rangle$, then

$$
\rho^{(1)}=|\psi_1\rangle\langle\psi_1|, \qquad \rho^{(2)}=|\psi_2\rangle\langle\psi_2|.
$$

### General partial trace

For $\rho \in \mathcal{D}(\mathcal{H}_1 \otimes \cdots \otimes \mathcal{H}_N)$, the reduced state on subsystem $k$ is the unique $\rho^{(k)}$ satisfying

$$
\operatorname{tr}(\rho^{(k)}F_k)=\operatorname{tr}(\rho \tilde{F}_k),
$$

where

$$
\tilde{F}_k = I \otimes \cdots \otimes I \otimes F_k \otimes I \otimes \cdots \otimes I.
$$

In coordinates,

$$
\langle i_k|\rho^{(k)}|j_k\rangle
=
\sum_{i_1,\dots,\widehat{i_k},\dots,i_N}
\langle i_1 \dots i_k \dots i_N | \rho | i_1 \dots j_k \dots i_N \rangle.
$$

This is the partial trace over all subsystems except $k$.

### Cyclicity of partial trace

For simple tensors,

$$
\operatorname{tr}_1(A \otimes B)=\operatorname{tr}(A)\,B.
$$

Also partial trace is cyclic in the factors that are traced out.

This is used repeatedly in subsystem calculations.

### Local unitary action

If $|\widetilde{\Psi}\rangle=(U \otimes V)|\Psi\rangle$, then

$$
\widetilde{\rho}_1 = U\rho_1U^\dagger, \qquad \widetilde{\rho}_2 = V\rho_2V^\dagger.
$$

So local unitaries act independently on the reduced states.

### Local measurement with forgotten outcome

> 💡 **Recall (Quantum Foundations):** If a measurement is performed on one subsystem and the outcome is not communicated, the reduced state of the other subsystem does not change.

Let $\rho^{AB}$ be a bipartite state and let Alice measure

$$
M_A=\sum_{\lambda} \lambda P_\lambda.
$$

If outcome $\lambda$ occurs, then

$$
\rho_\lambda = \frac{(P_\lambda \otimes I)\rho(P_\lambda \otimes I)}{\operatorname{tr}(\rho(P_\lambda \otimes I))}.
$$

If Bob does not know the outcome, then his post-measurement state is

$$
\sum_\lambda \operatorname{tr}(\rho(P_\lambda \otimes I)) \, \operatorname{tr}_A(\rho_\lambda)=\operatorname{tr}_A(\rho)=\rho_B.
$$

This is the no-communication theorem in this setting.

## 5 Schmidt Form and Entanglement

> 💡 **Recall (Quantum Foundations):** Bipartite pure states admit a Schmidt decomposition, and local mixedness of the reductions is the signature of entanglement.

### Algebra fact

For any linear map $F$:

1. $\ker(F)=\ker(F^\dagger F)$ and $\ker(F^\dagger)=\ker(FF^\dagger)$
2. $FF^\dagger$ and $F^\dagger F$ have the same non-zero eigenvalues with the same multiplicities

### Schmidt decomposition

Let $\mathcal{H}_1 \cong \mathbb{C}^d \cong \mathcal{H}_2$ and

$$
|\Psi\rangle=\sum_{i,j=1}^d C_{ij}|i\rangle\otimes|j\rangle.
$$

There exist local unitaries $\widetilde{U},\widetilde{V}$ such that

$$
(\widetilde{U}\otimes\widetilde{V})|\Psi\rangle=\sum_{i=1}^d \sqrt{p_i}\,|i\rangle\otimes|i\rangle
$$

with $p_i \ge 0$ and $\sum_i p_i=1$.

Equivalently,

$$
|\Psi\rangle=\sum_{i=1}^d \sqrt{p_i}\,|u_i\rangle\otimes|v_i\rangle.
$$

### Reduced states in Schmidt form

The reduced states are

$$
\rho_1=\sum_i p_i |u_i\rangle\langle u_i|, \qquad \rho_2=\sum_i p_i |v_i\rangle\langle v_i|.
$$

Hence $\rho_1$ and $\rho_2$ have the same non-zero spectrum.

### Separable vs entangled

$|\Psi\rangle$ is separable iff it is a simple tensor iff exactly one Schmidt coefficient is non-zero.

Otherwise $|\Psi\rangle$ is entangled.

### Entanglement entropy

For a pure bipartite state,

$$
S_E(|\Psi\rangle)=S(\rho_1)=S(\rho_2)=-\sum_i p_i \log p_i.
$$

Facts:

1. $S_E=0$ iff $|\Psi\rangle$ is separable
2. $S_E$ is invariant under local unitaries
3. $S_E$ is maximal and equal to $\log d$ for

$$
|\Psi_{\max}\rangle = \frac{1}{\sqrt{d}}\sum_{i=0}^{d-1}|i,i\rangle
$$

where $\rho_1=\rho_2=\frac{1}{d}I$

### Creating a mixed state by forgetting an outcome

If Alice measures

$$
F=\sum_{\lambda \in \sigma(F)} \lambda P_\lambda
$$

on repeated copies of $|\psi\rangle$, but Bob does not know the outcome, then Bob describes the system by

$$
\rho = \sum_{\lambda \in \sigma(F)} P_\lambda |\psi\rangle\langle\psi| P_\lambda.
$$

## 6 Bell States, Teleportation, Superdense Coding, No-Cloning

> 💡 **Recall (Quantum Foundations):** Bell-basis measurement transfers the unknown qubit to Bob up to a Pauli correction, superdense coding reverses this logic, and non-orthogonal states cannot be cloned.

### Bell basis

$$
|\Phi_\pm\rangle = \frac{1}{\sqrt{2}}(|00\rangle \pm |11\rangle), \qquad
|\Psi_\pm\rangle = \frac{1}{\sqrt{2}}(|01\rangle \pm |10\rangle).
$$

### Quantum teleportation

Initial state:

$$
|\psi\rangle^{A'}|\Psi_-\rangle^{AB}, \qquad |\psi\rangle = a|0\rangle+b|1\rangle.
$$

After rewriting in the Bell basis of $A'A$,

$$
|\psi\rangle^{A'}|\Psi_-\rangle^{AB}
=
\frac{1}{2}\left(
|\Psi_-\rangle^{A'A}\sigma_0|\psi\rangle^B
+|\Phi_-\rangle^{A'A}\sigma_1|\psi\rangle^B
+|\Phi_+\rangle^{A'A}(-i\sigma_2)|\psi\rangle^B
+|\Psi_+\rangle^{A'A}\sigma_3|\psi\rangle^B
\right)
$$

up to global phases.

So if Alice measures the Bell basis and obtains outcome $x \in \{0,1,2,3\}$, then Bob's qubit is $\sigma_x|\psi\rangle$ up to phase.

After Alice sends two classical bits, Bob applies the corresponding Pauli correction and recovers $|\psi\rangle$.

### Superdense coding

Shared resource:

$$
|\Phi_+\rangle^{AB}=\frac{1}{\sqrt{2}}(|00\rangle+|11\rangle).
$$

Alice encodes $x \in \{0,1,2,3\}$ by applying $\sigma_x$ on her qubit:

$$
\sigma_0 \otimes I : |\Phi_+\rangle \mapsto |\Phi_+\rangle
$$

$$
\sigma_1 \otimes I : |\Phi_+\rangle \mapsto |\Psi_+\rangle
$$

$$
\sigma_2 \otimes I : |\Phi_+\rangle \mapsto -i|\Psi_-\rangle
$$

$$
\sigma_3 \otimes I : |\Phi_+\rangle \mapsto |\Phi_-\rangle.
$$

Bob measures in the Bell basis and recovers $x$ with certainty.

So one transmitted qubit + one shared Bell pair can send two classical bits.

### No-cloning theorem

Assume a unitary cloner exists:

$$
U(|0\rangle|\psi\rangle)=|\psi\rangle|\psi\rangle
$$

for all $|\psi\rangle$.

Then for two states $|\psi_1\rangle, |\psi_2\rangle$,

$$
\langle \psi_1|\psi_2\rangle
=
\langle 0,\psi_1|U^\dagger U|0,\psi_2\rangle
=
\langle \psi_1,\psi_1|\psi_2,\psi_2\rangle
=
\langle \psi_1|\psi_2\rangle^2.
$$

Hence only $\langle \psi_1|\psi_2\rangle \in \{0,1\}$ is possible.

So arbitrary non-orthogonal states cannot be cloned.

## 7 Generalized Measurements and POVMs

> 💡 **Recall (Quantum Foundations):** A generalized measurement is a family $\{M_x\}$ with $\sum_x M_x^\dagger M_x=I$; the probability is computed from $M_x^\dagger M_x$ and the post-measurement state from $M_x$.

### Generalized measurement on pure states

Let $\{M_x\}_{x \in [m]}$ be operators on $\mathcal{H}$ such that

$$
\sum_{x \in [m]} M_x^\dagger M_x = I.
$$

If the input state is $|\psi\rangle$, then

$$
P_x = \langle \psi|M_x^\dagger M_x|\psi\rangle
$$

and post-measurement state

$$
|\psi_x\rangle = \frac{1}{\sqrt{P_x}}M_x|\psi\rangle.
$$

### Generalized measurement on mixed states

If the input state is $\rho$, then

$$
p_x=\operatorname{tr}(M_x^\dagger M_x \rho)
$$

and

$$
\sigma_x=\frac{1}{p_x}M_x \rho M_x^\dagger.
$$

### Dilation theorem

Every generalized measurement can be realized by:

1. adding an ancilla $R$
2. applying a unitary $U^{RA}$
3. performing a projective measurement on $R$

More precisely, if $\{M_x\}_{x \in [m]}$ is a generalized measurement, then there exists an ancilla of dimension $m$ and a unitary $U^{RA}$ such that the induced statistics and post-measurement states are exactly the same.

### Composition

If $\{M_x\}_{x \in [m]}$ and $\{N_y\}_{y \in [n]}$ are generalized measurements, then

$$
\{M_xN_y\}_{x,y}
$$

is also a generalized measurement.

### Classical-quantum state after recording the outcome

If the outcome is recorded in a classical register $X$, then

$$
\sigma^{XA}=\sum_x p_x |x\rangle\langle x|^X \otimes \sigma_x^A.
$$

This is a cq-state.

### POVM

If we only care about probabilities, define

$$
\Lambda_x := M_x^\dagger M_x.
$$

Then each $\Lambda_x \ge 0$ and

$$
\sum_x \Lambda_x = I.
$$

Such a family $\{\Lambda_x\}$ is a POVM.

Probabilities are

$$
p_x = \operatorname{tr}(\rho \Lambda_x).
$$

Important:

1. every generalized measurement defines a POVM via $\Lambda_x=M_x^\dagger M_x$
2. one POVM can come from many different measurement operators $\{M_x\}$

## 8 Quantum Tomography and Open-System Evolution

> 💡 **Recall (Quantum Foundations):** To reconstruct an unknown state, one needs a POVM spanning the real vector space of Hermitian operators; physical evolution of open systems is described by linear CPTP maps.

### Informationally complete POVM

A POVM $\{\Lambda_x\}_{x \in [m]}$ is informationally complete if

$$
\operatorname{Herm}(\mathcal{H})=\operatorname{span}_{\mathbb{R}}\{\Lambda_x\}_{x \in [m]}.
$$

Since

$$
\dim_{\mathbb{R}}\operatorname{Herm}(\mathcal{H})=d^2,
$$

an IC-POVM must have at least $d^2$ outcomes.

If $m=d^2$, then $\{\Lambda_x\}$ is a basis of $\operatorname{Herm}(\mathcal{H})$.

### State reconstruction

Let $\{\Gamma_x\}$ be the dual basis of $\{\Lambda_x\}$:

$$
\operatorname{tr}(\Lambda_x \Gamma_y)=\delta_{xy}.
$$

If

$$
p_x=\operatorname{tr}(\Lambda_x \rho),
$$

then

$$
\rho=\sum_{x=1}^{d^2} p_x \Gamma_x.
$$

So the outcome probabilities determine $\rho$ completely.

### Open-system evolution

An open-system evolution is a linear map

$$
\mathcal{E}:\mathcal{L}(A)\to\mathcal{L}(B).
$$

Physical requirements:

1. linearity
2. trace preservation
3. complete positivity

Such a map is called a quantum channel or CPTP map.

### Complete positivity

$\mathcal{E}$ is $k$-positive if

$$
(\operatorname{id}_R \otimes \mathcal{E})(\rho^{RA}) \ge 0
$$

for all $\rho^{RA}\ge 0$ and all reference systems $R$ with $|R|=k$.

$\mathcal{E}$ is completely positive if it is $k$-positive for all $k$.

### Example: transpose is positive but not completely positive

The transpose map

$$
\mathcal{T}(\rho)=\rho^T
$$

takes positive matrices to positive matrices, but

$$
(\operatorname{id}\otimes \mathcal{T})(\Phi_+)
$$

is not positive.

So positivity is not enough for physical evolution; complete positivity is required.

## 9 Quantum Channels and Choi Representation

> 💡 **Recall (Quantum Foundations):** A channel is a linear CPTP map, and complete positivity is equivalent to positivity of the Choi matrix.

### Basic examples

#### Unitary / isometric channel

If $\Lambda : A \to B$ is an isometry, then

$$
\mathcal{E}(\rho)=\Lambda \rho \Lambda^\dagger
$$

is completely positive.

It is trace preserving iff

$$
\Lambda^\dagger \Lambda = I.
$$

#### Trace non-increasing maps

For a single Kraus operator $\Lambda$,

$$
\mathcal{E}(\rho)=\Lambda \rho \Lambda^\dagger
$$

is trace non-increasing iff

$$
\Lambda^\dagger \Lambda \le I.
$$

### Dual map

For $\mathcal{E} : \mathcal{L}(A)\to\mathcal{L}(B)$, the dual map $\mathcal{E}^* : \mathcal{L}(B)\to\mathcal{L}(A)$ is defined by

$$
\langle \sigma, \mathcal{E}(\rho)\rangle_{HS}
=
\langle \mathcal{E}^*(\sigma), \rho\rangle_{HS}.
$$

If

$$
\mathcal{E}(\rho)=\Lambda \rho \Lambda^\dagger,
$$

then

$$
\mathcal{E}^*(\sigma)=\Lambda^\dagger \sigma \Lambda.
$$

### Choi matrix

Let $|A|=d$ and define the unnormalized maximally entangled vector

$$
|\Omega^{A\tilde{A}}\rangle=\sum_{x=1}^d |x\rangle^A|x\rangle^{\tilde{A}},
$$

with projector

$$
\Omega^{A\tilde{A}}=|\Omega^{A\tilde{A}}\rangle\langle\Omega^{A\tilde{A}}|
=
\sum_{x,y=1}^d |x\rangle\langle y|^A \otimes |x\rangle\langle y|^{\tilde{A}}.
$$

For $\mathcal{E}\in\mathcal{L}(A \to B)$, define

$$
J_{\mathcal{E}}^{AB} := \mathcal{E}^{\tilde{A}\to B}(\Omega^{A\tilde{A}}).
$$

Equivalently,

$$
J_{\mathcal{E}}^{AB}
=
\sum_{x,y=1}^d |x\rangle\langle y|^A \otimes \mathcal{E}(|x\rangle\langle y|^{\tilde{A}}).
$$

### Recovering the channel from the Choi matrix

For every $\rho \in \mathcal{L}(A)$,

$$
\mathcal{E}(\rho)=\operatorname{tr}_A\left[J_{\mathcal{E}}^{AB}(\rho^T \otimes I^B)\right].
$$

### Choi criterion

$$
\mathcal{E} \text{ is completely positive } \iff J_{\mathcal{E}}^{AB}\ge 0.
$$

For channels,

$$
\mathcal{E} \text{ is trace preserving } \iff \operatorname{tr}_B(J_{\mathcal{E}}^{AB})=I^A.
$$

So

$$
\mathcal{E}\in \operatorname{CPTP}(A \to B)
\iff
J_{\mathcal{E}}^{AB}\ge 0
\text{ and }
\operatorname{tr}_B(J_{\mathcal{E}}^{AB})=I^A.
$$

## 10 cq-Channels, Measurement-Prepare Channels, Entanglement Breaking, LOCC

> 💡 **Recall (Quantum Foundations):** Channels with separable Choi matrices are exactly the measurement-prepare / entanglement-breaking channels.

### Preparation channel / cq-channel

Let

$$
\Delta(\rho)=\sum_{x=1}^d \langle x|\rho|x\rangle |x\rangle\langle x|
$$

be the completely dephasing map in the computational basis.

A preparation channel satisfies

$$
\mathcal{E}\circ\Delta=\mathcal{E}.
$$

Then

$$
\mathcal{E}(\rho)=\sum_{x=1}^d \langle x|\rho|x\rangle \sigma_x
$$

for states $\sigma_x$.

Its Choi matrix is

$$
J_{\mathcal{E}}^{AB}=\sum_x |x\rangle\langle x|^A \otimes \sigma_x^B,
$$

which is a cq-state.

### Kraus form of a cq-channel

If $\{|y^B\rangle\}_{y=1}^{|B|}$ is a basis of $B$, then

$$
M_{xy}:=\sqrt{\sigma_x}\,|y^B\rangle\langle x^A|
$$

gives

$$
\mathcal{E}(\rho)=\sum_{x,y} M_{xy}\rho M_{xy}^\dagger.
$$

### Measurement-prepare channel

Given a POVM $\{\Lambda_z\}_{z=1}^m$ and output states $\{\sigma_z^B\}_{z=1}^m$,

$$
\mathcal{E}(\rho)=\sum_{z=1}^m \operatorname{tr}(\Lambda_z \rho)\,\sigma_z^B.
$$

Its Choi matrix is

$$
J_{\mathcal{E}}^{AB}=\sum_{z=1}^m \Lambda_z^T \otimes \sigma_z^B.
$$

So $J_{\mathcal{E}}^{AB}$ is separable.

### Entanglement-breaking channels

A channel $\mathcal{E}\in\operatorname{CPTP}(A \to B)$ is entanglement-breaking if for every reference system $R$ and every $\rho^{RA}$,

$$
(\operatorname{id}^R \otimes \mathcal{E}^{A \to B})(\rho^{RA})
$$

is separable across $R:B$.

Theorem:

$$
\mathcal{E} \text{ is entanglement-breaking } \iff \mathcal{E} \text{ is measurement-prepare }.
$$

Equivalently:

$$
\mathcal{E} \text{ is entanglement-breaking } \iff J_{\mathcal{E}}^{AB} \text{ is separable}.
$$

### LOCC

LOCC = local operations + classical communication.

Facts:

1. LOCC cannot create entanglement from separable states
2. LOCC cannot increase entanglement
3. Separable states can be generated by LOCC

Typical separable state:

$$
\rho^{AB}=\sum_x p_x \rho_x^A \otimes \sigma_x^B.
$$

### Moving Bob's measurement to Alice for pure states

Let $|\psi^{AB}\rangle$ be a bipartite pure state and let $\{N_x\}$ be measurement operators on Bob with

$$
\sum_x N_x^\dagger N_x = I_B.
$$

Then there exist operators $M_x$ on Alice and unitaries $V_x$ on Bob such that

$$
(I \otimes N_x)|\psi^{AB}\rangle = (M_x \otimes V_x)|\psi^{AB}\rangle.
$$

So every measurement Bob performs on a pure bipartite state can be simulated by a measurement on Alice, up to a unitary correction on Bob.

## 11 Matrix Lie Groups and Lie Algebras

### Matrix Lie groups

Let $\mathbb{K}=\mathbb{R},\mathbb{C}$.

$$
GL(n,\mathbb{K})=\{A\in M_n(\mathbb{K}) : \det(A)\neq 0\}.
$$

A matrix Lie group $G$ is a closed subgroup of $GL(n,\mathbb{K})$.

Examples:

1. $SL(n,\mathbb{K})=\{A : \det(A)=1\}$
2. $U(n)=\{U : UU^\dagger=I\}$
3. $SU(n)=\{U\in U(n) : \det(U)=1\}$
4. $O(n)=\{O : OO^T=I\}$
5. $SO(n)=\{O\in O(n) : \det(O)=1\}$

### Lie group homomorphism

$\Phi:G\to H$ is a Lie group homomorphism if

1. $\Phi(g_1g_2)=\Phi(g_1)\Phi(g_2)$
2. $\Phi(I)=I$
3. $\Phi$ is continuous

### Lie algebra

A Lie algebra is a vector space $\mathfrak{g}$ with bilinear bracket $[\cdot,\cdot]$ satisfying

1. $[X,Y]=-[Y,X]$
2. $[X,[Y,Z]]+[Y,[Z,X]]+[Z,[X,Y]]=0$

Matrix example:

$$
[A,B]=AB-BA.
$$

### Lie algebra of a matrix Lie group

For a matrix Lie group $G$,

$$
\operatorname{Lie}(G)=\{X : e^{tX}\in G \ \forall t \in \mathbb{R}\}.
$$

Examples:

$$
\operatorname{Lie}(GL(n,\mathbb{K}))=\mathfrak{gl}(n,\mathbb{K})=M_n(\mathbb{K})
$$

$$
\operatorname{Lie}(SL(n,\mathbb{K}))=\mathfrak{sl}(n,\mathbb{K})=\{X : \operatorname{tr}(X)=0\}
$$

$$
\operatorname{Lie}(U(n))=\mathfrak{u}(n)=\{X : X^\dagger=-X\}
$$

$$
\operatorname{Lie}(SU(n))=\mathfrak{su}(n)=\{X : X^\dagger=-X,\ \operatorname{tr}(X)=0\}
$$

$$
\operatorname{Lie}(O(n))=\mathfrak{o}(n)=\{X : X^T=-X\}
$$

$$
\operatorname{Lie}(SO(n))=\mathfrak{so}(n)=\{X : X^T=-X\}.
$$

### One-parameter subgroup

A one-parameter subgroup is a continuous map $g:\mathbb{R}\to G$ such that

$$
g(0)=I, \qquad g(t+s)=g(t)g(s).
$$

Then

$$
g(t)=e^{tX}
$$

for a unique $X \in \operatorname{Lie}(G)$.

### Lie product formula

For $X,Y \in M_n(\mathbb{C})$,

$$
e^{X+Y}=\lim_{m\to\infty}\left(e^{X/m}e^{Y/m}\right)^m.
$$

### Adjoint action

For $g \in G$,

$$
\operatorname{Ad}_g(X)=gXg^{-1}.
$$

For $X \in \mathfrak{g}$, define

$$
\operatorname{ad}_X(Y)=\left.\frac{d}{dt}\right|_{t=0}\operatorname{Ad}_{e^{tX}}(Y)=[X,Y].
$$

Also

$$
\operatorname{Ad}_{e^X}(Y)=e^{\operatorname{ad}_X}(Y)=Y+[X,Y]+\frac{1}{2!}[X,[X,Y]]+\cdots.
$$

## 12 The Adjoint Representation of $SU(d)$

### Hilbert-Schmidt structure on $\mathfrak{su}(d)$

For $X,Y \in \mathfrak{su}(d)$ define

$$
(X|Y)_{H-S}=d\,\operatorname{tr}(X^\dagger Y)=-d\,\operatorname{tr}(XY).
$$

Since $\dim_{\mathbb{R}}\mathfrak{su}(d)=d^2-1$, the adjoint action gives

$$
\operatorname{Ad}:SU(d)\to SO(\mathfrak{su}(d)) \cong SO(d^2-1).
$$

### Orthogonality

For every $U \in SU(d)$,

$$
(\operatorname{Ad}_U(X)|\operatorname{Ad}_U(Y))_{H-S}=(X|Y)_{H-S}.
$$

So $\operatorname{Ad}_U$ is an orthogonal transformation.

### Matrix elements

If $\{\gamma_1,\dots,\gamma_{d^2-1}\}$ is an orthonormal basis of $\mathfrak{su}(d)$, then

$$
[\operatorname{Ad}_U]_{ij}=(\gamma_i|\operatorname{Ad}_U(\gamma_j))_{H-S}
=
-d\,\operatorname{tr}(\gamma_i U\gamma_jU^{-1}).
$$

## 13 The Case of $SU(2)$, Pauli Matrices, and the Bloch Sphere

> 💡 **Recall (Quantum Foundations):** $\operatorname{Herm}(\mathbb{C}^2)$ has basis $I,\sigma_x,\sigma_y,\sigma_z$, so every qubit state can be expanded in the Pauli basis.

### Pauli matrices

$$
\sigma_x=\sigma_1=
\begin{pmatrix}
0&1\\
1&0
\end{pmatrix},
\qquad
\sigma_y=\sigma_2=
\begin{pmatrix}
0&-i\\
i&0
\end{pmatrix},
\qquad
\sigma_z=\sigma_3=
\begin{pmatrix}
1&0\\
0&-1
\end{pmatrix},
\qquad
\sigma_0=I.
$$

Algebra:

$$
\sigma_j \sigma_k = \delta_{jk}I + i\sum_l \epsilon_{jkl}\sigma_l
$$

$$
[\sigma_j,\sigma_k]=2i\sum_l \epsilon_{jkl}\sigma_l
$$

$$
\{\sigma_j,\sigma_k\}=2\delta_{jk}I.
$$

### $\mathfrak{su}(2)$ basis

Define

$$
\widetilde{\sigma}_k=-\frac{i}{2}\sigma_k.
$$

Then

$$
[\widetilde{\sigma}_j,\widetilde{\sigma}_k]=\sum_l \epsilon_{jkl}\widetilde{\sigma}_l
$$

and

$$
\mathfrak{su}(2)=\operatorname{span}_{\mathbb{R}}\{\widetilde{\sigma}_1,\widetilde{\sigma}_2,\widetilde{\sigma}_3\}.
$$

### Isomorphism $\mathfrak{su}(2)\cong \mathbb{R}^3$

For $\vec{a}=(a_1,a_2,a_3)\in\mathbb{R}^3$, write

$$
\vec{a}\cdot\widehat{\vec{\sigma}}=a_1\widetilde{\sigma}_1+a_2\widetilde{\sigma}_2+a_3\widetilde{\sigma}_3.
$$

Then

$$
(\vec{a}\cdot\widehat{\vec{\sigma}} \,|\, \vec{b}\cdot\widehat{\vec{\sigma}})_{H-S}=\vec{a}\cdot\vec{b}
$$

and

$$
[\vec{a}\cdot\widehat{\vec{\sigma}}, \vec{b}\cdot\widehat{\vec{\sigma}}]
=
(\vec{a}\times\vec{b})\cdot\widehat{\vec{\sigma}}.
$$

So $\mathfrak{su}(2)$ is the Lie-algebraic version of $\mathbb{R}^3$ with the cross product.

### Exponentiation and the map $SU(2)\to SO(3)$

Every $U \in SU(2)$ can be written as

$$
U=e^{\alpha \hat{n}\cdot \widehat{\vec{\sigma}}}
=
e^{-i\frac{\alpha}{2}\hat{n}\cdot \vec{\sigma}}
$$

for a unit vector $\hat{n}\in\mathbb{R}^3$.

Using $(\hat{n}\cdot\vec{\sigma})^2=I$,

$$
e^{-i\frac{\alpha}{2}\hat{n}\cdot \vec{\sigma}}
=
\cos\left(\frac{\alpha}{2}\right)I
-i\sin\left(\frac{\alpha}{2}\right)\hat{n}\cdot\vec{\sigma}.
$$

Under the adjoint action, $U$ induces a rotation in $\mathbb{R}^3$:

$$
\operatorname{Ad}:SU(2)\to SO(3)
$$

and this map is surjective and $2$-to-$1$.

### Qubits

A qubit is a system with $\mathcal{H}\cong \mathbb{C}^2$.

Choose basis $\{|0\rangle,|1\rangle\}$ where $|0\rangle,|1\rangle$ are eigenvectors of $\sigma_z$.

### Bloch form of a qubit state

Any Hermitian $2\times 2$ matrix can be written as

$$
a_0 I + \vec{a}\cdot\vec{\sigma}.
$$

The trace-$1$ condition gives $a_0=\frac{1}{2}$, so every qubit state has the form

$$
\rho_{\vec{x}}=\frac{1}{2}(I+\vec{x}\cdot\vec{\sigma})
$$

for some $\vec{x}\in\mathbb{R}^3$.

Its eigenvalues are

$$
q_{1,2}=\frac{1}{2}\pm\frac{1}{2}|\vec{x}|.
$$

Hence

$$
\rho_{\vec{x}}\ge 0 \iff |\vec{x}|\le 1.
$$

So qubit states are parametrized by the unit ball in $\mathbb{R}^3$.

### Pure qubit states

Using

$$
(\vec{x}\cdot\vec{\sigma})^2=|\vec{x}|^2 I,
$$

we get

$$
\rho_{\vec{x}}^2=\rho_{\vec{x}} \iff |\vec{x}|=1.
$$

Therefore:

$$
\rho_{\vec{x}} \text{ is pure } \iff |\vec{x}|=1.
$$

The boundary $|\vec{x}|=1$ is the Bloch sphere.

### Unitary action on a qubit

Every unitary $2\times 2$ matrix can be written as

$$
U_{\mathrm{full}}=e^{i\phi}U,
\qquad
U\in SU(2).
$$

The global phase cancels in state evolution:

$$
(e^{i\phi}U)\rho(e^{i\phi}U)^\dagger = U\rho U^\dagger.
$$

So on Bloch vectors, a unitary acts as a rotation:

$$
U\rho_{\vec{x}}U^\dagger
=
\frac{1}{2}\left(I + (R\vec{x})\cdot\vec{\sigma}\right)
$$

for some $R \in SO(3)$.

### Qudits

Let $\{\gamma_1,\dots,\gamma_{d^2-1}\}$ be an orthonormal basis of $\mathfrak{su}(d)$.

Using the anti-Hermitian basis convention of these notes, a $d$-level state can be written as

$$
\rho=\frac{1}{d}\left(I+i\vec{x}\cdot\vec{\gamma}\right).
$$

Positivity imposes nontrivial constraints on $\vec{x}\in\mathbb{R}^{d^2-1}$.

Under unitary conjugation,

$$
\rho \longmapsto U\rho U^\dagger
$$

and the generalized Bloch vector transforms by the adjoint representation of $SU(d)$.
