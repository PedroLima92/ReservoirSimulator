- [ ] Lines that should enter: 
  - [ ] If line has children, skip to next 
  - [ ] Edges with material id == fracture; 
  - [ ] Lines whose elder is an edge of an element with no father; 
- [ ] Faces that should enter: 
- [ ] // fracture surface elements 
- [ ] Faces with no children  
- [ ] + material id of fracture surface  
- [ ] + elder has no neighbour volume through (n-1)side; 
- [ ] // interface of macro elements 
- [ ] If(has father) continue; 
- [ ] material id intact → enters with old code → continue 
- [ ] If(does not have 3D neighbour through side (n-1)) continue; 
- [ ] Set curve loop 
- [ ] Get j rib (elder); 
- [ ] Queue youngest children of jrib; 
- [ ] Set counter k of how many children have been added to the curve loop 
- [ ] Get child who's neighbour of face through node 0 
- [ ] If child side in node 0 is zero orientation = 1 
- [ ] Else orientation = -1 
- [ ] Remove child from queue 
- [ ] Next child will be neighbour of previous child through opposite node; 
- [ ] Stop when k == n  
- [ ] Close curve loop after all jribs have been added 
- [ ] Lines-in-Surface  
- [ ] Line{a,b,c} In Surface {x} (if this is the only way, code needs an std::set<int> to remove duplicates) 
- [ ] Loop over 2D elements; 
- [ ] HasFather → continue 
- [ ] !HasSubelements → continue 
- [ ] If mesh_dim == 3 && has no neighbour through side (n-1) → continue 
- [ ] Get youngestChildren 
- [ ] Std::set candidate_ribs 
- [ ] Loop through children and get all ribs of material fracture 
- [ ] Print "Curve{" 
- [ ] Loop through candidates 
- [ ] Get candidate elder 
- [ ] If elder has mesh_dim-D neighbour through side (n-1) with no father → continue 
- [ ] Print candidate 
- [ ] Print "In Surface{iel};\n" 