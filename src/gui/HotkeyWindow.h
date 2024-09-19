class HotkeyWindow : public Showable {
private:
    int KeyOrders[5][14] = {
            {
                81,
                82,
                83,
                84,
                85,
                86,
                87,
                88,
                89,
                90,
                101,
                102,
                0xFF,
                0xFF,
                },
            {
                41,
                42,
                43,
                44,
                45,
                46,
                47,
                48,
                49,
                50,
                103,
                104,
                105,
                0xFF,
                },
            {
                51,
                52,
                53,
                54,
                55,
                56,
                57,
                58,
                59,
                106,
                107,
                0xFF,
                0xFF,
                0xFF,
                },
            {
                3,
                60,
                61,
                62,
                63,
                64,
                65,
                66,
                108,
                109,
                110,
                // 4,
                0xFF,
                0xFF,
                },
            {
                1,
                5,
                7,
                // 6,
                // 2,
                0xFF,
                0xFF,
                0xFF,
                0xFF,
                0xFF,
                0xFF,
                0xFF,
                0xFF,
                0xFF,
                }
    };
    int editingHotkey = -1;
    int keyAlphabetCount = 256;
    bool edited = false;
    bool keyDown[256] = {};
    void HotKeySPrintf(char* buffer, size_t bufferSize, const char* fmt, ...);
    void GetHotKeyLib(unsigned int functionKeys, char* buffer, size_t bufferSize, const char* functionLib);
    void addHotKeySelectable(HotKey& hotkey, int i);
    void setupKeyboard(HotKey& hotkey);
public:
    void render() override;
    void onExit();
    void onEnter();
    void onKeyEvent(const shishan::KeyEvent& event);
    HotkeyWindow();

};