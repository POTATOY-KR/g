#include "minimax_tree.h"

vector<node> depth1;

// AI�� �鵹 �������� �ۼ���

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

				if (map[x][y][turn + 1] > gameset.ai.fourweight) { // ���� ������ ���� �ٷ� ����ϴ� �ڸ�
					*a = x;
					*b = y;
					out << "tree.depth1.code1" << endl;
					return;
				}
				if (map[x][y][2 - turn] > gameset.ai.fourweight) { // ��밡 ������ ��밡 �ٷ� ����ϴ� �ڸ�
					if (finp1 != 0) {
						finp1 = 0;

						// ��� ��� ����
						depth1.clear();

						//log
						out << "delete all node (depth 1)" << endl;

						// �ڽ� ��� x,y �����
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
						//�ڽ� ��� x,y �����
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

				if (finp1 != 0) { // ���� ��찡 ������ �Ʒ��� ���� �ǹ̰� ����

					if (map[x][y][turn + 1] > gameset.ai.threeweight) { // ���� ������ �����Ͽ� ���� ����ϴ� �ڸ�
						if (finp2 != 0) {
							finp2 = 0;
							// ��� ��� ����
							depth1.clear();

							//log
							out << "delete all node (depth 1)" << endl;

							// �ڽ� ��� x,y �����
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
							// �ڽ� ��� x,y �����
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

					if (finp2 != 0) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

						if (map[x][y][2 - turn] > gameset.ai.threeweight) { // ��밡 ������ �����Ͽ� ��밡 ����ϴ� �ڸ�
							if (finp2 != 1) {
								finp2 = 1;
								// ��� ��� ����
								depth1.clear();

								//log
								out << "delete all node (depth 1)" << endl;

								// �ڽ� ��� x,y �����
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
								// �ڽ� ��� x,y �����
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

						if (finp2 == -1) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

							if (map[x][y][turn + 1] > gameset.ai.tfweight) { // ���� ������ 3*4�� ��������� �ڸ�
								// 33/44�� �ƴϸ�
								int crk = check_rule(x, y, map);
								if (crk != 0) {
									if (chap != 0) {
										chap == 0;
										// ��� ��� ����
										depth1.clear();

										//log
										out << "delete all node (depth 1)" << endl;

										// �ڽ� ��� x,y �����
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
										// �ڽ� ��� x,y �����
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

							if (chap != 0) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

								if (map[x][y][2 - turn] > gameset.ai.tfweight) { // ��밡 ������ 3*4�� ��������� �ڸ�
									// 33/44 �� �ƴϸ�
									int crk = check_rule(x, y, map);
									if (crk != 0) {
										if (chap != 1) {
											chap = 1;
											// ��� ��� ����
											depth1.clear();

											//log
											out << "delete all node (depth 1)" << endl;

											// �ڽ� ��� x,y �����
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
											// �ڽ� ��� x,y �����
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
									// �ڽ� ��� x,y �����
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
	// depth 1 �Ϸ�

	//log
	out << "depth 1 finished. depth1 size is " << depth1.size() << endl;

	// depth1�� ��尡 ������ �� �� �ֺ��� ����
	if (depth1.size() == 0) {
		no_node(a, b);
		return;
	}

	// depth 2
	finp1 = -1;
	finp2 = -1;
	chap = -1;
	// ��� depth 1�� ��忡 ����
	for (int n_n = 0; n_n < depth1.size(); n_n++) {

		// map�� ������ �迭 cp_map�� �ش� ����� �ڸ��� �� ���� ���� ����ġ ���
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
					if (depth1[n_n].cp_map[x][y][2 - turn] > gameset.ai.fourweight) { // ��밡 ������ ��밡 �ٷ� ����ϴ� �ڸ�

						//�θ� ��� ����
						depth1[n_n].c_node.clear();
						depth1.erase(depth1.begin() + n_n, depth1.begin() + n_n + 1);

						//log
						out << "delete parent node (depth 2)" << endl;

						//���� depth 1 ��� ����
						bk_ck = 0;
						break;
					}

					if (depth1[n_n].cp_map[x][y][turn + 1] > gameset.ai.fourweight) { // ���� ������ ���� �ٷ� ����ϴ� �ڸ�
						if (finp1 == -1) {
							finp1 == 0;
							// ��� ��� ����
							depth1[n_n].c_node.clear();

							//log
							out << "delete all node (depth 2)" << endl;

							// �ڽ� ��� x,y �����
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
							// �ڽ� ��� x,y �����
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

					if (finp1 != 0) { // ���� ��찡 ������ �Ʒ��� ���� �ǹ̰� ����

						if (depth1[n_n].cp_map[x][y][2 - turn] > gameset.ai.threeweight) { // ��밡 ������ �����Ͽ� ��밡 ����ϴ� �ڸ�
							if (finp2 != 0) {
								finp2 = 0;
								// ��� ��� ����
								depth1[n_n].c_node.clear();

								//log
								out << "delete all node (depth 2)" << endl;

								// �ڽ� ��� x,y �����
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
								// �ڽ� ��� x,y �����
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

						if (finp2 != 0) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

							if (depth1[n_n].cp_map[x][y][turn + 1] > gameset.ai.threeweight) { // ���� ������ �����Ͽ� ���� ����ϴ� �ڸ�
								if (finp2 != 1) {
									finp2 = 1;
									// ��� ��� ����
									depth1[n_n].c_node.clear();

									//log
									out << "delete all node (depth 2)" << endl;

									// �ڽ� ��� x,y �����
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
									// �ڽ� ��� x,y �����
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

							if (finp2 == -1) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

								if (depth1[n_n].cp_map[x][y][2 - turn] > gameset.ai.tfweight) { // ��밡 ������ 3*4�� ��������� �ڸ�
									// 33/44 �� �ƴϸ�
									int crk = check_rule(x, y, depth1[n_n].cp_map);
									if (crk != 0) {
										if (chap != 0) {
											chap = 0;
											// ��� ��� ����
											depth1[n_n].c_node.clear();

											//log
											out << "delete all node (depth 2)" << endl;

											// �ڽ� ��� x,y �����
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
											// �ڽ� ��� x,y �����
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

								if (chap != 0) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

									if (depth1[n_n].cp_map[x][y][turn + 1] > gameset.ai.tfweight) { // ���� ������ 3*4�� ��������� �ڸ�
									// 33/44 �� �ƴϸ�
										int crk = check_rule(x, y, depth1[n_n].cp_map);
										if (crk != 0) {
											if (chap != 1) {
												chap == 1;
												// ��� ��� ����
												depth1[n_n].c_node.clear();

												//log
												out << "delete all node (depth 2)" << endl;

												// �ڽ� ��� x,y �����
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
												// �ڽ� ��� x,y �����
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
										// �ڽ� ��� x,y �����
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
	// depth 2 �Ϸ�

	//log
	out << "depth 2 finished" << endl;

	// depth 3
	finp1 = -1;
	finp2 = -1;
	chap = -1;
	// ��� depth 1�� ��忡 ����
	for (int n_n = 0; n_n < depth1.size(); n_n++) {
		// �� depth 1�� ��� �ڽ� ��忡 ����
		for (int n_n2 = 0; n_n2 < depth1[n_n].c_node.size(); n_n2++) {
			// �θ� ����� cp_map�� ������ cp_map�� �ش� ����� �ڸ��� ��� ���� ���� ����ġ ���
			depth1[n_n].c_node[n_n2].cp_map[depth1[n_n].c_node[n_n2].x][depth1[n_n].c_node[n_n2].y][0] = 2 - turn;

			//log
			out << "get_cp_st_arr start" << endl;

			get_cp_st_arr(&(depth1[n_n].c_node[n_n2]));

			//log
			out << "get_cp_st_arr finish" << endl;

			for (int x = 1; x < MSIZE + 1; x++) {
				for (int y = 1; y < MSIZE + 1; y++) {

					if (map[x][y][turn + 1] != 0 || map[x][y][2 - turn] != 0) { // ����ġ�� 0�� �ƴϸ�

						if (map[x][y][turn + 1] > gameset.ai.fourweight) { // ���� ������ ���� �ٷ� ����ϴ� �ڸ�
							finp1 = 0;
							// �ڽ� ��� x,y �����
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

						if (finp1 == 0) { // ���� ��찡 ������ �Ʒ��� ���� �ǹ̰� ����

							if (map[x][y][2 - turn] > gameset.ai.fourweight) { // ��밡 ������ ��밡 �ٷ� ����ϴ� �ڸ�
								if (finp1 != 1) {
									finp1 = 1;
									// ��� ��� ����
									depth1[n_n].c_node[n_n2].c_node.clear();

									//log
									out << "delete all node (depth 3)" << endl;

									// �ڽ� ��� x,y �����
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
									// �ڽ� ��� x,y �����
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

							if (finp1 == -1) { // ���� ��찡 ������ �Ʒ��� ���� �ǹ̰� ����

								if (map[x][y][turn + 1] > gameset.ai.threeweight) { // ���� ������ �����Ͽ� ���� ����ϴ� �ڸ�
									if (finp2 != 0) {
										finp2 = 0;
										// ��� ��� ����
										depth1[n_n].c_node[n_n2].c_node.clear();

										//log
										out << "delete all node (depth 3)" << endl;

										// �ڽ� ��� x,y �����
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
										// �ڽ� ��� x,y �����
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

								if (finp2 != 0) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

									if (map[x][y][2 - turn] > gameset.ai.threeweight) { // ��밡 ������ �����Ͽ� ��밡 ����ϴ� �ڸ�
										if (finp2 != 1) {
											finp2 = 1;
											// ��� ��� ����
											depth1[n_n].c_node[n_n2].c_node.clear();

											//log
											out << "delete all node (depth 3)" << endl;

											// �ڽ� ��� x,y �����
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
											// �ڽ� ��� x,y �����
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

									if (finp2 == -1) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

										if (map[x][y][turn + 1] > gameset.ai.tfweight) { // ���� ������ 3*4�� ��������� �ڸ�
											int crk = check_rule(x, y, depth1[n_n].c_node[n_n2].cp_map);
											if (crk != 0) {
												if (chap != 0) {
													chap == 0;
													// ��� ��� ����
													depth1[n_n].c_node[n_n2].c_node.clear();

													//log
													out << "delete all node (depth 3)" << endl;

													// �ڽ� ��� x,y �����
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
													// �ڽ� ��� x,y �����
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

										if (chap != 0) { // ���� ��찡 �ִٸ� �Ʒ��� ���� �ǹ̰� ����

											if (map[x][y][2 - turn] > gameset.ai.tfweight) { // ��밡 ������ 3*4�� ��������� �ڸ�
												int crk = check_rule(x, y, depth1[n_n].c_node[n_n2].cp_map);
												if (crk != 0) {
													if (chap != 1) {
														chap = 1;
														// ��� ��� ����
														depth1[n_n].c_node[n_n2].c_node.clear();

														//log
														out << "delete all node (depth 3)" << endl;

														// �ڽ� ��� x,y �����
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
														// �ڽ� ��� x,y �����
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
												// �ڽ� ��� x,y �����
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
	// depth 3 �Ϸ�

	//log
	out << "depth 3 finished" << endl;

	// depth 1�� ��� ��忡 ����
	for (int n_n = 0; n_n < depth1.size(); n_n++) {

		// �� depth 1�� ��� �ڽ� ��忡 ����
		for (int n_n2 = 0; n_n2 < depth1[n_n].c_node.size(); n_n2++) {

			// �� depth 2�� ��� �ڽ� ��忡 ����
			for (int n_n3 = 0; n_n3 < depth1[n_n].c_node[n_n2].c_node.size(); n_n3++) {

				// �θ� ����� cp_map�� ������ cp_map�� �ش� ����� �ڸ��� ��� ���� ���� ����ġ ���
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

	// �� ����� �¸� ���� Ȯ��
	int d1 = 0, dif = -2000000000;
	for (int n_n = 0; n_n < depth1.size(); n_n++) {
		for (int n_n2 = 0; n_n2 < depth1[n_n].c_node.size(); n_n2++) {
			for (int n_n3 = 0; n_n3 < depth1[n_n].c_node[n_n2].c_node.size(); n_n3++) {

				// �¸� ����� ��� �ش� ����� depth1 x, y�� ��ȯ
				if (depth1[n_n].c_node[n_n2].c_node[n_n3].win == 1) {
					*a = depth1[n_n].x;
					*b = depth1[n_n].y;

					//log
					out << "winning node exist" << endl;

					return;
				}

				//�¸� ��� ���� �� (�� ����ġ �ִ밪) - (�� ����ġ �ִ밪)�� ���� ū ��� ����
				int w_max = 0;
				int b_max = 0;
				for (int i = 1; i < MSIZE + 1; i++) {
					for (int j = 1; j < MSIZE + 1; j++) {
						// �ڽ� ����ġ �ִ밪 ���ϱ�
						if (w_max < depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][turn + 1]) {
							w_max = depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][turn + 1];
						}

						// ��� ����ġ �ִ밪 ���ϱ�
						if (b_max < depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][2 - turn]) {
							b_max = depth1[n_n].c_node[n_n2].c_node[n_n3].cp_map[i][j][2 - turn];
						}
					}
				}

				// ���� �ִ밪 ���ϱ�
				if (dif < w_max - b_max) {
					dif = w_max - b_max;
					d1 = n_n;
				}
			}
		}
	}

	// ���� ���� ū ����� depth1 ����� x,y ��ȯ
	*a = depth1[d1].x;
	*b = depth1[d1].y;

	out << "x = " << depth1[d1].x << " , y = " << depth1[d1].y << endl;

	return;
}


void get_cp_st_arr(node* n) {
	int s_arr[11];
	int p_arr[11];
	int color = 0;

	// map �迭 ����ġ �ʱ�ȭ
	for (int x = 1; x < MSIZE + 1; x++) {
		for (int y = 1; y < MSIZE + 1; y++) {
			n->cp_map[x][y][turn + 1] = 0;
			n->cp_map[x][y][2 - turn] = 0;
		}
	}

	for (int x = 1; x < MSIZE + 1; x++) {
		for (int y = 1; y < MSIZE + 1; y++) {
			if (n->cp_map[x][y][0] == 1 || n->cp_map[x][y][0] == 2) {	// �鵹 �Ǵ� �浹�� ���� ������
				color = n->cp_map[x][y][0];
				// stone_arr, point_arr �ʱ�ȭ
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// ���� ��ġ�� ��
				s_arr[5] = n->cp_map[x][y][0];

				// ���η� �� ���� 5ĭ�� �ޱ�
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
				// ���ι����� ����ġ ���
				addpoint(s_arr, p_arr);

				// map �迭�� ����ġ ���ϱ�
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
				// ���ι��� ��

				// stone_arr, point_arr �ʱ�ȭ
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// ���� ��ġ�� ��
				s_arr[5] = n->cp_map[x][y][0];

				// ���η� �� ���� 5ĭ�� �ޱ�
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
				// ���ι����� ����ġ ���
				addpoint(s_arr, p_arr);

				// map �迭�� ����ġ ���ϱ�
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
				// ���ι��� ��

				// stone_arr, point_arr �ʱ�ȭ
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// ���� ��ġ�� ��
				s_arr[5] = n->cp_map[x][y][0];

				// �»� �밢������ �� ���� 5ĭ�� �ޱ�
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
				// �»� �밢�������� ����ġ ���
				addpoint(s_arr, p_arr);

				// map �迭�� ����ġ ���ϱ�
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
				// �»� �밢������ ��

				// stone_arr, point_arr �ʱ�ȭ
				for (int i = 0; i < 11; i++) {
					s_arr[i] = 3;
					p_arr[i] = 0;
				}
				// ���� ��ġ�� ��
				s_arr[5] = n->cp_map[x][y][0];

				// ��� �밢������ �� ���� 5ĭ�� �ޱ�
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
				// ��� �밢�������� ����ġ ���
				addpoint(s_arr, p_arr);

				// map �迭�� ����ġ ���ϱ�
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
				// ��� �밢������ ��
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