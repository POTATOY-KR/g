#include "minimax_tree.h"

vector<node> depth1;

// AI가 백돌 기준으로 작성됨

void tree(int* a, int* b) {
	if (turn == 1 && map[((MSIZE - 1) / 2) + 1][((MSIZE - 1) / 2) + 1][0] == 0) {
		*a = ((MSIZE - 1) / 2) + 1;
		*b = ((MSIZE - 1) / 2) + 1;
		return;
	}
	//log
	out << "tree func start" << endl;

	depth1.clear();

	//log
	out << "reset node" << endl;

	// depth 1
	int finp1 = -1;
	int finp2 = -1;
	int chap = -1;

	for (int x = 1; x < MSIZE + 1; x++) {
		for (int y = 1; y < MSIZE + 1; y++) {
			if (map[x][y][turn + 1] != 0 || map[x][y][2 - turn] != 0) {

				//log
				out << "x : " << x << ", y : " << y << " - ";

				if (map[x][y][turn + 1] > gameset.ai.fourweight) { // 내가 놓으면 내가 바로 우승하는 자리
					*a = x;
					*b = y;
					out << "tree.depth1.code1" << endl;
					return;
				}
				if (map[x][y][2 - turn] > gameset.ai.fourweight) { // 상대가 놓으면 상대가 바로 우승하는 자리
					if (finp1 != 0) {
						finp1 = 0;

						// 모든 노드 삭제
						depth1.clear();

						//log
						out << "delete all node (depth 1)" << endl;

						// 자식 노드 x,y 만들기
						node n;
						n.x = x;
						n.y = y;
						for (int i = 0; i < MSIZE + 2; i++) {
							for (int j = 0; j < MSIZE + 2; j++) {
								for (int k = 0; k < 4; k++) {
									n.cp_map[i][j][k] = map[i][j][k];
								}
							}
						}
						depth1.push_back(n);

						//log
						out << "tree.depth1.code2" << endl;
					}
					else {
						//자식 노드 x,y 만들기
						node n;
						n.x = x;
						n.y = y;
						for (int i = 0; i < MSIZE + 2; i++) {
							for (int j = 0; j < MSIZE + 2; j++) {
								for (int k = 0; k < 4; k++) {
									n.cp_map[i][j][k] = map[i][j][k];
								}
							}
						}
						depth1.push_back(n);

						//log
						out << "tree.depth1.code2" << endl;
					}
				}

				if (finp1 != 0) { // 위의 경우가 있으면 아래의 경우는 의미가 없음

					if (map[x][y][turn + 1] > gameset.ai.threeweight) { // 내가 놓으면 다음턴에 내가 우승하는 자리
						if (finp2 != 0) {
							finp2 = 0;
							// 모든 노드 삭제
							depth1.clear();

							//log
							out << "delete all node (depth 1)" << endl;

							// 자식 노드 x,y 만들기
							node n;
							n.x = x;
							n.y = y;
							for (int i = 0; i < MSIZE + 2; i++) {
								for (int j = 0; j < MSIZE + 2; j++) {
									for (int k = 0; k < 4; k++) {
										n.cp_map[i][j][k] = map[i][j][k];
									}
								}
							}
							depth1.push_back(n);

							//log
							out << "tree.depth1.code3" << endl;
						}
						else {
							// 자식 노드 x,y 만들기
							node n;
							n.x = x;
							n.y = y;
							for (int i = 0; i < MSIZE + 2; i++) {
								for (int j = 0; j < MSIZE + 2; j++) {
									for (int k = 0; k < 4; k++) {
										n.cp_map[i][j][k] = map[i][j][k];
									}
								}
							}
							depth1.push_back(n);

							//log
							out << "tree.depth1.code3" << endl;
						}
					}

					if (finp2 != 0) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

						if (map[x][y][2 - turn] > gameset.ai.threeweight) { // 상대가 놓으면 다음턴에 상대가 우승하는 자리
							if (finp2 != 1) {
								finp2 = 1;
								// 모든 노드 삭제
								depth1.clear();

								//log
								out << "delete all node (depth 1)" << endl;

								// 자식 노드 x,y 만들기
								node n;
								n.x = x;
								n.y = y;
								for (int i = 0; i < MSIZE + 2; i++) {
									for (int j = 0; j < MSIZE + 2; j++) {
										for (int k = 0; k < 4; k++) {
											n.cp_map[i][j][k] = map[i][j][k];
										}
									}
								}
								depth1.push_back(n);

								//log
								out << "tree.depth1.code4" << endl;
							}
							else {
								// 자식 노드 x,y 만들기
								node n;
								n.x = x;
								n.y = y;
								for (int i = 0; i < MSIZE + 2; i++) {
									for (int j = 0; j < MSIZE + 2; j++) {
										for (int k = 0; k < 4; k++) {
											n.cp_map[i][j][k] = map[i][j][k];
										}
									}
								}
								depth1.push_back(n);

								//log
								out << "tree.depth1.code4" << endl;
							}
						}

						if (finp2 == -1) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

							if (map[x][y][turn + 1] > gameset.ai.tfweight) { // 내가 놓으면 3*4가 만들어지는 자리
								// 33/44가 아니면
								int crk = check_rule(x, y, map);
								if (crk != 0) {
									if (chap != 0) {
										chap == 0;
										// 모든 노드 삭제
										depth1.clear();

										//log
										out << "delete all node (depth 1)" << endl;

										// 자식 노드 x,y 만들기
										node n;
										n.x = x;
										n.y = y;
										for (int i = 0; i < MSIZE + 2; i++) {
											for (int j = 0; j < MSIZE + 2; j++) {
												for (int k = 0; k < 4; k++) {
													n.cp_map[i][j][k] = map[i][j][k];
												}
											}
										}
										depth1.push_back(n);

										//log
										out << "tree.depth1.code5" << endl;
									}
									else {
										// 자식 노드 x,y 만들기
										node n;
										n.x = x;
										n.y = y;
										for (int i = 0; i < MSIZE + 2; i++) {
											for (int j = 0; j < MSIZE + 2; j++) {
												for (int k = 0; k < 4; k++) {
													n.cp_map[i][j][k] = map[i][j][k];
												}
											}
										}
										depth1.push_back(n);

										//log
										out << "tree.depth1.code5" << endl;
									}
								}
								else {
									y++;
									continue;
								}
							}

							if (chap != 0) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

								if (map[x][y][2 - turn] > gameset.ai.tfweight) { // 상대가 놓으면 3*4가 만들어지는 자리
									// 33/44 가 아니면
									int crk = check_rule(x, y, map);
									if (crk != 0) {
										if (chap != 1) {
											chap = 1;
											// 모든 노드 삭제
											depth1.clear();

											//log
											out << "delete all node (depth 1)" << endl;

											// 자식 노드 x,y 만들기
											node n;
											n.x = x;
											n.y = y;
											for (int i = 0; i < MSIZE + 2; i++) {
												for (int j = 0; j < MSIZE + 2; j++) {
													for (int k = 0; k < 4; k++) {
														n.cp_map[i][j][k] = map[i][j][k];
													}
												}
											}
											depth1.push_back(n);

											//log
											out << "tree.depth1.code6" << endl;
										}
										else {
											// 자식 노드 x,y 만들기
											node n;
											n.x = x;
											n.y = y;
											for (int i = 0; i < MSIZE + 2; i++) {
												for (int j = 0; j < MSIZE + 2; j++) {
													for (int k = 0; k < 4; k++) {
														n.cp_map[i][j][k] = map[i][j][k];
													}
												}
											}
											depth1.push_back(n);

											//log
											out << "tree.depth1.code6" << endl;
										}
									}
									else {
										y++;
										continue;
									}
								}

								if (chap != 1) {
									// 자식 노드 x,y 만들기
									node n;
									n.x = x;
									n.y = y;
									for (int i = 0; i < MSIZE + 2; i++) {
										for (int j = 0; j < MSIZE + 2; j++) {
											for (int k = 0; k < 4; k++) {
												n.cp_map[i][j][k] = map[i][j][k];
											}
										}
									}
									depth1.push_back(n);

									//log
									out << "tree.depth1.code7" << endl;
								}
							}
						}
					}
				}
				out << "node : ";
				for (int k = 0; k < depth1.size(); k++) {
					out << "(" << depth1[k].x << ", " << depth1[k].y << ") ";
				}
				out << endl;
			}
		}
	}
	// depth 1 완료

	//log
	out << "depth 1 finished. depth1 size is " << depth1.size() << endl;

	// depth1의 노드가 없으면 내 돌 주변에 놓음
	if (depth1.size() == 0) {
		no_node(a, b);
		return;
	}

	// depth 2
	finp1 = -1;
	finp2 = -1;
	chap = -1;
	// 모든 depth 1의 노드에 대해
	for (int n_n = 0; n_n < depth1.size(); n_n++) {

		// map을 복사한 배열 cp_map에 해당 노드의 자리에 내 돌을 놓고 가중치 계산
		for (int i = 0; i < MSIZE + 2; i++) {
			for (int j = 0; j < MSIZE + 2; j++) {
				for (int k = 0; k < 4; k++) {
					depth1[n_n].cp_map[i][j][k] = map[i][j][k];
				}
			}
		}
		depth1[n_n].cp_map[depth1[n_n].x][depth1[n_n].y][0] = turn + 1;

		//log
		out << "get_cp_st_arr start" << endl;

		get_cp_st_arr(&depth1[n_n]);

		//log
		out << "get_cp_st_arr finish" << endl;

		int bk_ck = -1;
		for (int x = 1; x < MSIZE + 1; x++) {
			for (int y = 1; y < MSIZE + 1; y++) {
				if (depth1[n_n].cp_map[x][y][turn + 1] != 0 || depth1[n_n].cp_map[x][y][2 - turn] != 0) {
					if (depth1[n_n].cp_map[x][y][2 - turn] > gameset.ai.fourweight) { // 상대가 놓으면 상대가 바로 우승하는 자리

						//부모 노드 삭제
						depth1[n_n].c_node.clear();
						depth1.erase(depth1.begin() + n_n, depth1.begin() + n_n + 1);

						//log
						out << "delete parent node (depth 2)" << endl;

						//다음 depth 1 노드 진행
						bk_ck = 0;
						break;
					}

					if (depth1[n_n].cp_map[x][y][turn + 1] > gameset.ai.fourweight) { // 내가 놓으면 내가 바로 우승하는 자리
						if (finp1 == -1) {
							finp1 == 0;
							// 모든 노드 삭제
							depth1[n_n].c_node.clear();

							//log
							out << "delete all node (depth 2)" << endl;

							// 자식 노드 x,y 만들기
							node n;
							n.x = x;
							n.y = y;
							for (int i = 0; i < MSIZE + 2; i++) {
								for (int j = 0; j < MSIZE + 2; j++) {
									for (int k = 0; k < 4; k++) {
										n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
									}
								}
							}
							depth1[n_n].c_node.push_back(n);

							//log
							out << "tree.depth2.code1" << endl;
						}
						else {
							// 자식 노드 x,y 만들기
							node n;
							n.x = x;
							n.y = y;
							for (int i = 0; i < MSIZE + 2; i++) {
								for (int j = 0; j < MSIZE + 2; j++) {
									for (int k = 0; k < 4; k++) {
										n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
									}
								}
							}
							depth1[n_n].c_node.push_back(n);

							//log
							out << "tree.depth2.code1" << endl;
						}
					}

					if (finp1 != 0) { // 위의 경우가 있으면 아래의 경우는 의미가 없음

						if (depth1[n_n].cp_map[x][y][2 - turn] > gameset.ai.threeweight) { // 상대가 놓으면 다음턴에 상대가 우승하는 자리
							if (finp2 != 0) {
								finp2 = 0;
								// 모든 노드 삭제
								depth1[n_n].c_node.clear();

								//log
								out << "delete all node (depth 2)" << endl;

								// 자식 노드 x,y 만들기
								node n;
								n.x = x;
								n.y = y;
								for (int i = 0; i < MSIZE + 2; i++) {
									for (int j = 0; j < MSIZE + 2; j++) {
										for (int k = 0; k < 4; k++) {
											n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
										}
									}
								}
								depth1[n_n].c_node.push_back(n);

								//log
								out << "tree.depth2.code2" << endl;
							}
							else {
								// 자식 노드 x,y 만들기
								node n;
								n.x = x;
								n.y = y;
								for (int i = 0; i < MSIZE + 2; i++) {
									for (int j = 0; j < MSIZE + 2; j++) {
										for (int k = 0; k < 4; k++) {
											n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
										}
									}
								}
								depth1[n_n].c_node.push_back(n);

								//log
								out << "tree.depth2.code2" << endl;
							}
						}

						if (finp2 != 0) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

							if (depth1[n_n].cp_map[x][y][turn + 1] > gameset.ai.threeweight) { // 내가 놓으면 다음턴에 내가 우승하는 자리
								if (finp2 != 1) {
									finp2 = 1;
									// 모든 노드 삭제
									depth1[n_n].c_node.clear();

									//log
									out << "delete all node (depth 2)" << endl;

									// 자식 노드 x,y 만들기
									node n;
									n.x = x;
									n.y = y;
									for (int i = 0; i < MSIZE + 2; i++) {
										for (int j = 0; j < MSIZE + 2; j++) {
											for (int k = 0; k < 4; k++) {
												n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
											}
										}
									}
									depth1[n_n].c_node.push_back(n);

									//log
									out << "tree.depth2.code3" << endl;
								}
								else {
									// 자식 노드 x,y 만들기
									node n;
									n.x = x;
									n.y = y;
									for (int i = 0; i < MSIZE + 2; i++) {
										for (int j = 0; j < MSIZE + 2; j++) {
											for (int k = 0; k < 4; k++) {
												n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
											}
										}
									}
									depth1[n_n].c_node.push_back(n);

									//log
									out << "tree.depth2.code3" << endl;
								}
							}

							if (finp2 == -1) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

								if (depth1[n_n].cp_map[x][y][2 - turn] > gameset.ai.tfweight) { // 상대가 놓으면 3*4가 만들어지는 자리
									// 33/44 가 아니면
									int crk = check_rule(x, y, depth1[n_n].cp_map);
									if (crk != 0) {
										if (chap != 0) {
											chap = 0;
											// 모든 노드 삭제
											depth1[n_n].c_node.clear();

											//log
											out << "delete all node (depth 2)" << endl;

											// 자식 노드 x,y 만들기
											node n;
											n.x = x;
											n.y = y;
											for (int i = 0; i < MSIZE + 2; i++) {
												for (int j = 0; j < MSIZE + 2; j++) {
													for (int k = 0; k < 4; k++) {
														n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
													}
												}
											}
											depth1[n_n].c_node.push_back(n);

											//log
											out << "tree.depth2.code4" << endl;
										}
										else {
											// 자식 노드 x,y 만들기
											node n;
											n.x = x;
											n.y = y;
											for (int i = 0; i < MSIZE + 2; i++) {
												for (int j = 0; j < MSIZE + 2; j++) {
													for (int k = 0; k < 4; k++) {
														n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
													}
												}
											}
											depth1[n_n].c_node.push_back(n);

											//log
											out << "tree.depth2.code4" << endl;
										}
									}
									else {
										y++;
										continue;
									}
								}

								if (chap != 0) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

									if (depth1[n_n].cp_map[x][y][turn + 1] > gameset.ai.tfweight) { // 내가 놓으면 3*4가 만들어지는 자리
									// 33/44 가 아니면
										int crk = check_rule(x, y, depth1[n_n].cp_map);
										if (crk != 0) {
											if (chap != 1) {
												chap == 1;
												// 모든 노드 삭제
												depth1[n_n].c_node.clear();

												//log
												out << "delete all node (depth 2)" << endl;

												// 자식 노드 x,y 만들기
												node n;
												n.x = x;
												n.y = y;
												for (int i = 0; i < MSIZE + 2; i++) {
													for (int j = 0; j < MSIZE + 2; j++) {
														for (int k = 0; k < 4; k++) {
															n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
														}
													}
												}
												depth1[n_n].c_node.push_back(n);

												//log
												out << "tree.depth2.code5" << endl;
											}
											else {
												// 자식 노드 x,y 만들기
												node n;
												n.x = x;
												n.y = y;
												for (int i = 0; i < MSIZE + 2; i++) {
													for (int j = 0; j < MSIZE + 2; j++) {
														for (int k = 0; k < 4; k++) {
															n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
														}
													}
												}
												depth1[n_n].c_node.push_back(n);

												//log
												out << "tree.depth2.code5" << endl;
											}
										}
										else {
											y++;
											continue;
										}
									}

									if (chap != 1) {
										// 자식 노드 x,y 만들기
										node n;
										n.x = x;
										n.y = y;
										for (int i = 0; i < MSIZE + 2; i++) {
											for (int j = 0; j < MSIZE + 2; j++) {
												for (int k = 0; k < 4; k++) {
													n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
												}
											}
										}
										depth1[n_n].c_node.push_back(n);

										//log
										out << "tree.depth2.code6" << endl;
									}
								}
							}
						}
					}
				}
			}
			if (bk_ck == 0) {
				break;
			}
		}
	}
	// depth 2 완료

	//log
	out << "depth 2 finished" << endl;

	// depth 3
	finp1 = -1;
	finp2 = -1;
	chap = -1;
	// 모든 depth 1의 노드에 대해
	for (int n_n = 0; n_n < depth1.size(); n_n++) {
		// 각 depth 1의 모든 자식 노드에 대해
		for (int n_n2 = 0; n_n2 < depth1[n_n].c_node.size(); n_n2++) {
			// 부모 노드의 cp_map을 복사한 cp_map에 해당 노드의 자리에 상대 돌을 놓고 가중치 계산
			depth1[n_n].c_node[n_n2].cp_map[depth1[n_n].c_node[n_n2].x][depth1[n_n].c_node[n_n2].y][0] = 2 - turn;

			//log
			out << "get_cp_st_arr start" << endl;

			get_cp_st_arr(&(depth1[n_n].c_node[n_n2]));

			//log
			out << "get_cp_st_arr finish" << endl;

			for (int x = 1; x < MSIZE + 1; x++) {
				for (int y = 1; y < MSIZE + 1; y++) {

					if (map[x][y][turn + 1] != 0 || map[x][y][2 - turn] != 0) { // 가중치가 0이 아니면

						if (map[x][y][turn + 1] > gameset.ai.fourweight) { // 내가 놓으면 내가 바로 우승하는 자리
							finp1 = 0;
							// 자식 노드 x,y 만들기
							node n;
							n.x = x;
							n.y = y;
							for (int i = 0; i < MSIZE + 2; i++) {
								for (int j = 0; j < MSIZE + 2; j++) {
									for (int k = 0; k < 4; k++) {
										n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
									}
								}
							}
							n.win = 1;
							depth1[n_n].c_node[n_n2].c_node.push_back(n);

							//log
							out << "tree.depth3.code1" << endl;
						}

						if (finp1 == 0) { // 위의 경우가 있으면 아래의 경우는 의미가 없음

							if (map[x][y][2 - turn] > gameset.ai.fourweight) { // 상대가 놓으면 상대가 바로 우승하는 자리
								if (finp1 != 1) {
									finp1 = 1;
									// 모든 노드 삭제
									depth1[n_n].c_node[n_n2].c_node.clear();

									//log
									out << "delete all node (depth 3)" << endl;

									// 자식 노드 x,y 만들기
									node n;
									n.x = x;
									n.y = y;
									for (int i = 0; i < MSIZE + 2; i++) {
										for (int j = 0; j < MSIZE + 2; j++) {
											for (int k = 0; k < 4; k++) {
												n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
											}
										}
									}
									depth1[n_n].c_node[n_n2].c_node.push_back(n);

									//log
									out << "tree.depth3.code2" << endl;
								}
								else {
									// 자식 노드 x,y 만들기
									node n;
									n.x = x;
									n.y = y;
									for (int i = 0; i < MSIZE + 2; i++) {
										for (int j = 0; j < MSIZE + 2; j++) {
											for (int k = 0; k < 4; k++) {
												n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
											}
										}
									}
									depth1[n_n].c_node[n_n2].c_node.push_back(n);

									//log
									out << "tree.depth3.code2" << endl;
								}
							}

							if (finp1 == -1) { // 위의 경우가 있으면 아래의 경우는 의미가 없음

								if (map[x][y][turn + 1] > gameset.ai.threeweight) { // 내가 놓으면 다음턴에 내가 우승하는 자리
									if (finp2 != 0) {
										finp2 = 0;
										// 모든 노드 삭제
										depth1[n_n].c_node[n_n2].c_node.clear();

										//log
										out << "delete all node (depth 3)" << endl;

										// 자식 노드 x,y 만들기
										node n;
										n.x = x;
										n.y = y;
										for (int i = 0; i < MSIZE + 2; i++) {
											for (int j = 0; j < MSIZE + 2; j++) {
												for (int k = 0; k < 4; k++) {
													n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
												}
											}
										}
										depth1[n_n].c_node[n_n2].c_node.push_back(n);

										//log
										out << "tree.depth3.code3" << endl;
									}
									else {
										// 자식 노드 x,y 만들기
										node n;
										n.x = x;
										n.y = y;
										for (int i = 0; i < MSIZE + 2; i++) {
											for (int j = 0; j < MSIZE + 2; j++) {
												for (int k = 0; k < 4; k++) {
													n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
												}
											}
										}
										depth1[n_n].c_node[n_n2].c_node.push_back(n);

										//log
										out << "tree.depth3.code3" << endl;
									}
								}

								if (finp2 != 0) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

									if (map[x][y][2 - turn] > gameset.ai.threeweight) { // 상대가 놓으면 다음턴에 상대가 우승하는 자리
										if (finp2 != 1) {
											finp2 = 1;
											// 모든 노드 삭제
											depth1[n_n].c_node[n_n2].c_node.clear();

											//log
											out << "delete all node (depth 3)" << endl;

											// 자식 노드 x,y 만들기
											node n;
											n.x = x;
											n.y = y;
											for (int i = 0; i < MSIZE + 2; i++) {
												for (int j = 0; j < MSIZE + 2; j++) {
													for (int k = 0; k < 4; k++) {
														n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
													}
												}
											}
											depth1[n_n].c_node[n_n2].c_node.push_back(n);

											//log
											out << "tree.depth3.code4" << endl;
										}
										else {
											// 자식 노드 x,y 만들기
											node n;
											n.x = x;
											n.y = y;
											for (int i = 0; i < MSIZE + 2; i++) {
												for (int j = 0; j < MSIZE + 2; j++) {
													for (int k = 0; k < 4; k++) {
														n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
													}
												}
											}
											depth1[n_n].c_node[n_n2].c_node.push_back(n);

											//log
											out << "tree.depth3.code4" << endl;
										}
									}

									if (finp2 == -1) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

										if (map[x][y][turn + 1] > gameset.ai.tfweight) { // 내가 놓으면 3*4가 만들어지는 자리
											int crk = check_rule(x, y, depth1[n_n].c_node[n_n2].cp_map);
											if (crk != 0) {
												if (chap != 0) {
													chap == 0;
													// 모든 노드 삭제
													depth1[n_n].c_node[n_n2].c_node.clear();

													//log
													out << "delete all node (depth 3)" << endl;

													// 자식 노드 x,y 만들기
													node n;
													n.x = x;
													n.y = y;
													for (int i = 0; i < MSIZE + 2; i++) {
														for (int j = 0; j < MSIZE + 2; j++) {
															for (int k = 0; k < 4; k++) {
																n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
															}
														}
													}
													depth1[n_n].c_node[n_n2].c_node.push_back(n);

													//log
													out << "tree.depth3.code5" << endl;
												}
												else {
													// 자식 노드 x,y 만들기
													node n;
													n.x = x;
													n.y = y;
													for (int i = 0; i < MSIZE + 2; i++) {
														for (int j = 0; j < MSIZE + 2; j++) {
															for (int k = 0; k < 4; k++) {
																n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
															}
														}
													}
													depth1[n_n].c_node[n_n2].c_node.push_back(n);

													//log
													out << "tree.depth3.code5" << endl;
												}
											}
											else {
												y++;
												continue;
											}
										}

										if (chap != 0) { // 위의 경우가 있다면 아래의 경우는 의미가 없음

											if (map[x][y][2 - turn] > gameset.ai.tfweight) { // 상대가 놓으면 3*4가 만들어지는 자리
												int crk = check_rule(x, y, depth1[n_n].c_node[n_n2].cp_map);
												if (crk != 0) {
													if (chap != 1) {
														chap = 1;
														// 모든 노드 삭제
														depth1[n_n].c_node[n_n2].c_node.clear();

														//log
														out << "delete all node (depth 3)" << endl;

														// 자식 노드 x,y 만들기
														node n;
														n.x = x;
														n.y = y;
														for (int i = 0; i < MSIZE + 2; i++) {
															for (int j = 0; j < MSIZE + 2; j++) {
																for (int k = 0; k < 4; k++) {
																	n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
																}
															}
														}
														depth1[n_n].c_node[n_n2].c_node.push_back(n);

														//log
														out << "tree.depth3.code6" << endl;
													}
													else {
														// 자식 노드 x,y 만들기
														node n;
														n.x = x;
														n.y = y;
														for (int i = 0; i < MSIZE + 2; i++) {
															for (int j = 0; j < MSIZE + 2; j++) {
																for (int k = 0; k < 4; k++) {
																	n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
																}
															}
														}
														depth1[n_n].c_node[n_n2].c_node.push_back(n);

														//log
														out << "tree.depth3.code6" << endl;
													}
												}
												else {
													y++;
													continue;
												}
											}

											if (chap != 1) {
												// 자식 노드 x,y 만들기
												node n;
												n.x = x;
												n.y = y;
												for (int i = 0; i < MSIZE + 2; i++) {
													for (int j = 0; j < MSIZE + 2; j++) {
														for (int k = 0; k < 4; k++) {
															n.cp_map[i][j][k] = depth1[n_n].cp_map[i][j][k];
														}
													}
												}
												depth1[n_n].c_node[n_n2].c_node.push_back(n);

												//log
												out << "tree.depth3.code7" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	// depth 3 완료

	//log
	out << "depth 3 finished" << endl;

	// depth 1의 모든 노드에 대해
	for (int n_n = 0; n_n < depth1.size(); n_n++) {

		// 각 depth 1의 모든 자식 노드에 대해
		for (int n_n2 = 0; n_n2 < depth1[n_n].c_node.size(); n_n2++) {

			// 각 depth 2의 모든 자식 노드에 대해
			for (int n_n3 = 0; n_n3 < depth1[n_n].c_node[n_n2].c_node.size(); n_n3++) {

				// 부모 노드의 cp_map을 복사한 cp_map에 해당 노드의 자리에 상대 돌을 놓고 가중치 계산
				depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[depth1[n_n].c_node[n_n2].c_node[n_n3].x][depth1[n_n].c_node[n_n2].c_node[n_n3].y][0] = turn + 1;

				//log
				out << "get_cp_st_arr start" << endl;

				get_cp_st_arr(&(depth1[n_n].c_node[n_n2].c_node[n_n3]));

				//log
				out << "get_cp_st_arr finish" << endl;
			}
		}
	}

	//log
	out << "calculate add point of all nodes" << endl;

	// 각 노드의 승리 여부 확인
	int d1 = 0, dif = -2000000000;
	for (int n_n = 0; n_n < depth1.size(); n_n++) {
		for (int n_n2 = 0; n_n2 < depth1[n_n].c_node.size(); n_n2++) {
			for (int n_n3 = 0; n_n3 < depth1[n_n].c_node[n_n2].c_node.size(); n_n3++) {

				// 승리 노드일 경우 해당 노드의 depth1 x, y값 반환
				if (depth1[n_n].c_node[n_n2].c_node[n_n3].win == 1) {
					*a = depth1[n_n].x;
					*b = depth1[n_n].y;

					//log
					out << "winning node exist" << endl;

					return;
				}

				//승리 노드 없을 시 (백 가중치 최대값) - (흑 가중치 최대값)이 가장 큰 노드 선택
				int w_max = 0;
				int b_max = 0;
				for (int i = 1; i < MSIZE + 1; i++) {
					for (int j = 1; j < MSIZE + 1; j++) {
						// 자신 가중치 최대값 구하기
						if (w_max < depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][turn + 1]) {
							w_max = depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][turn + 1];
						}

						// 상대 가중치 최대값 구하기
						if (b_max < depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][2 - turn]) {
							b_max = depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][2 - turn];
						}
					}
				}

				// 차의 최대값 구하기
				if (dif < w_max - b_max) {
					dif = w_max - b_max;
					d1 = n_n;
				}
			}
		}
	}

	// 차가 가장 큰 노드의 depth1 노드의 x,y 반환
	*a = depth1[d1].x;
	*b = depth1[d1].y;

	out << "x = " << depth1[d1].x << " , y = " << depth1[d1].y << endl;

	return;
}


void get_cp_st_arr(node* n) {
	int s_arr[11];
	int p_arr[11];
	int color = 0;

	// map 배열 가중치 초기화
	for (int x = 1; x < MSIZE + 1; x++) {
		for (int y = 1; y < MSIZE + 1; y++) {
			n->cp_map[x][y][turn + 1] = 0;
			n->cp_map[x][y][2 - turn] = 0;
		}
	}

	for (int x = 1; x < MSIZE + 1; x++) {
		for (int y = 1; y < MSIZE + 1; y++) {
			if (n->cp_map[x][y][0] == 1 || n->cp_map[x][y][0] == 2) {	// 백돌 또는 흑돌이 놓여 있으면
				color = n->cp_map[x][y][0];
				// stone_arr, point_arr 초기화
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// 현재 위치의 돌
				s_arr[5] = n->cp_map[x][y][0];

				// 가로로 각 방향 5칸씩 받기
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x][y - i][0] == 3) {
						break;
					}
					s_arr[5 - i] = n->cp_map[x][y - i][0];
				}
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x][y + i][0] == 3) {
						break;
					}
					s_arr[5 + i] = n->cp_map[x][y + i][0];
				}
				// 가로방향의 가중치 계산
				addpoint(s_arr, p_arr);

				// map 배열에 가중치 더하기
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x][y - i][0] == 3) {
						break;
					}
					n->cp_map[x][y - i][color] += p_arr[5 - i];
				}
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x][y + i][0] == 3) {
						break;
					}
					n->cp_map[x][y + i][color] += p_arr[5 + i];
				}
				// 가로방향 끝

				// stone_arr, point_arr 초기화
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// 현재 위치의 돌
				s_arr[5] = n->cp_map[x][y][0];

				// 세로로 각 방향 5칸씩 받기
				for (int i = 1; i < 6; i++) {
					s_arr[5 - i] = n->cp_map[x - i][y][0];
					if (n->cp_map[x - i][y][0] == 3) {
						break;
					}
				}
				for (int i = 1; i < 6; i++) {
					s_arr[5 + i] = n->cp_map[x + i][y][0];
					if (n->cp_map[x + i][y][0] == 3) {
						break;
					}
				}
				// 세로방향의 가중치 계산
				addpoint(s_arr, p_arr);

				// map 배열에 가중치 더하기
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x - i][y][0] == 3) {
						break;
					}
					n->cp_map[x - i][y][color] += p_arr[5 - i];
				}
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x + i][y][0] == 3) {
						break;
					}
					n->cp_map[x + i][y][color] += p_arr[5 + i];
				}
				// 세로방향 끝

				// stone_arr, point_arr 초기화
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// 현재 위치의 돌
				s_arr[5] = n->cp_map[x][y][0];

				// 좌상 대각선으로 각 방향 5칸씩 받기
				for (int i = 1; i < 6; i++) {
					s_arr[5 - i] = n->cp_map[x - i][y - i][0];
					if (n->cp_map[x - i][y - i][0] == 3) {
						break;
					}
				}
				for (int i = 1; i < 6; i++) {
					s_arr[5 + i] = n->cp_map[x + i][y + i][0];
					if (n->cp_map[x + i][y + i][0] == 3) {
						break;
					}
				}
				// 좌상 대각선방향의 가중치 계산
				addpoint(s_arr, p_arr);

				// map 배열에 가중치 더하기
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x - i][y - i][0] == 3) {
						break;
					}
					n->cp_map[x - i][y - i][color] += p_arr[5 - i];
				}
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x + i][y + i][0] == 3) {
						break;
					}
					n->cp_map[x + i][y + i][color] += p_arr[5 + i];
				}
				// 좌상 대각선방향 끝

				// stone_arr, point_arr 초기화
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// 현재 위치의 돌
				s_arr[5] = n->cp_map[x][y][0];

				// 우상 대각선으로 각 방향 5칸씩 받기
				for (int i = 1; i < 6; i++) {
					s_arr[5 - i] = n->cp_map[x - i][y + i][0];
					if (n->cp_map[x - i][y + i][0] == 3) {
						break;
					}
				}
				for (int i = 1; i < 6; i++) {
					s_arr[5 + i] = n->cp_map[x + i][y - i][0];
					if (n->cp_map[x + i][y - i][0] == 3) {
						break;
					}
				}
				// 우상 대각선방향의 가중치 계산
				addpoint(s_arr, p_arr);

				// map 배열에 가중치 더하기
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x - i][y + i][0] == 3) {
						break;
					}
					n->cp_map[x - i][y + i][color] += p_arr[5 - i];
				}
				for (int i = 1; i < 6; i++) {
					if (n->cp_map[x + i][y - i][0] == 3) {
						break;
					}
					n->cp_map[x + i][y - i][color] += p_arr[5 + i];
				}
				// 우상 대각선방향 끝
				color = 0;
			}
		}
	}
}

void no_node(int* a, int* b) {

	for (int i = 1; i < MSIZE + 1; i++) {
		for (int j = 1; j < MSIZE + 1; j++) {
			if (map[i][j][0] == turn + 1) {
				if (map[i - 1][j - 1][0] == 0) {
					*a = i - 1;
					*b = j - 1;
				}
				else if (map[i - 1][j][0] == 0) {
					*a = i - 1;
					*b = j;
				}
				else if (map[i - 1][j + 1][0] == 0) {
					*a = i - 1;
					*b = j + 1;
				}
				else if (map[i][j - 1][0] == 0) {
					*a = i;
					*b = j - 1;
				}
				else if (map[i][j + 1][0] == 0) {
					*a = i;
					*b = j + 1;
				}
				else if (map[i + 1][j - 1][0] == 0) {
					*a = i + 1;
					*b = j - 1;
				}
				else if (map[i + 1][j][0] == 0) {
					*a = i + 1;
					*b = j;
				}
				else if (map[i + 1][j + 1][0] == 0) {
					*a = i + 1;
					*b = j + 1;
				}
				else {
					j++;
					continue;
				}
				return;
			}
		}
	}
	if (map[(MSIZE - 1) / 2][((MSIZE - 1) / 2) + 2][0] == 0) {
		*a = (MSIZE - 1) / 2;
		*b = ((MSIZE - 1) / 2) + 2;
	}
	return;
}