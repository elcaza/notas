# ¿Qué es CVSS V3?
CVSS es un framework abierto y de uso universal que permite clasificar una vulnerabilidad en función de su impacto y severidad.

CVSS es un sistema de puntuación que proporciona un método estándar y abierto para estimar el impacto de una vulnerabilidad y  que se compone tres grupos principales de métricas: 
+ Base 
+ Temporal 
+ Entorno (Environmental). 

** Cada uno de estos grupos se compone a su vez de un conjunto de métricas.

# 1 Base Score:
Engloba las cualidades intrínsecas de una vulnerabilidad y que son independientes del tiempo y el entorno. Las métricas evaluadas en este grupo son:

## 1.1 Attack Vector (AV). 
Valores: [N,A,L,P] 
+ Network
+ Adjacent
+ Local 
+ Physical

## 1.2 Attack Complexity (AC)
Valores [L,H] 
+ Low
+ High

## 1.3 Privileges Required (PR)
Valores [N,L,H] 
+ None
+ Low
+ High

## 1.4 User Interaction (UI). 
Valores [N,R] 
+ None
+ Required

## 1.5 Scope (S)
Valores [U,C] 
+ Changed
+ Unchanged

## 1.6 Confidentiality (C)
Valores [N,L,H] 
+ High
+ Low
+ None

## 1.7 Integrity (I)
Valores [N,L,H] 
+ None
+ Low
+ High

## 1.8 Availability (A). 
Valores [H,L,N] 
+ High
+ Low
+ None

# 2 Temporal Score:
Características de la vulnerabilidad que cambian en el tiempo. 

## 2.1 Exploit Code Maturity (E)
Valores: [H,F,P,U,X] 
+ High
+ Functional
+ Proof-of-Concept
+ Unproven
+ Not Defined

## 2.2 Remediation Level (RL). 
Valores: [U,W,T,O,X] 
+ Unavailable
+ Workaround
+ Temporary Fix
+ Official Fix
+ Not Defined

## 2.3 Report Confidence (RC). 
Valores: [C,R,U,X] 
+ Confirmed
+ Reasonable
+ Unknown
+ Not Defined

# 3 Environmental Score:
Las características de la vulnerabilidad relacionadas con el entorno del usuario. 

## 3.1 Confidentiality Requirement (CR)
Valores: [H,M,L,X] 
+ High
+ Medium
+ Low
+ Not Defined

## 3.2 Integrity Requirement (IR)
Valores: [H,M,L,X] 
+ High
+ Medium
+ Low
+ Not Defined

## 3.3 Availability Requirement (AR)
Valores: [H,M,L,X] 
+ High
+ Medium
+ Low
+ Not Defined

## 3.4 Modified Attack Vector (MAV)
Valores: [N,AD,L,P,X] 
+ Network
+ Adjacent network
+ Local
+ Physical
+ Not Defined

## 3.5 Modified Attack Complexity (MAC)
Valores: [H,L,X] 
+ High
+ Low
+ Not Defined

## 3.6 Modified Privileges Required (MPR)
Valores: [H,L,N,X] 
+ High
+ Low
+ None
+ Not Defined

## 3.7 Modified User Interaction (MUI)
Valores: [R,N,X] 
+ Require
+ None
+ Not Defined

## 3.8 Modified Scope (MS)
Valores: [C,U,X] 
+ Changed
+ Unchanged
+ Not Defined

## 3.9 Modified Confidentiality (MC)
Valores: [H,L,N,X] 
+ High
+ Low
+ None
+ Not Defined

## 3.10 Modified Confidentiality (MI)
Valores: [H,L,N,X] 
+ High
+ Low
+ None
+ Not Defined

## 3.11 Modified Availability (MA)
Valores: [H,L,N,X] 
+ High
+ Low
+ None
+ Not Defined

# Referencias 

+ [Common Vulnerability Scoring System Calculator V3](https://nvd.nist.gov/vuln-metrics/cvss/v3-calculator)
+ [Métricas de evaluación de vulnerabilidades: CVSS 3.0](https://www.incibe-cert.es/blog/cvss3-0)