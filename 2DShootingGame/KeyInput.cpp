/*

int pad; // �W���C�p�b�h
int pov;

pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
pov = GetJoypadPOVState(DX_INPUT_PAD1, 0);
for (int i = 0; i < 28; i++) {
if (pad & (1 << i)) {
DrawFormatString(0, i * 15, GetColor(255, 255, 255), "%d�̃L�[��������Ă��܂��B",i);
}
}
// �\���L�[�m�F
for (int i = 28; i < 32; i++) {
if (pov == (31 - i) * 9000) {
DrawFormatString(0, (i-10) * 15, GetColor(255, 255, 255), "%d�̃L�[��������Ă��܂��B", i);
}
}
*/