// Copyright (c) 2011-2019 The coinBit Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZEO_QT_ASKPASSPHRASEDIALOG_H
#define ZEO_QT_ASKPASSPHRASEDIALOG_H

#include <QDialog>

#include <support/allocators/secure.h>

class WalletModel;

namespace Ui {
    class AskPassphraseDialog;
}

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,        /**< Ask passphrase twice and encrypt */
        UnlockStaking,  /**< Ask passphrase and unlock staking only */
        Unlock,         /**< Ask passphrase and unlock */
        ChangePass,     /**< Ask old passphrase + new passphrase twice */
        Decrypt         /**< Ask passphrase and decrypt wallet */
    };

    explicit AskPassphraseDialog(Mode mode, QWidget *parent, SecureString* passphrase_out = nullptr);
    ~AskPassphraseDialog();

    void accept();

    void setModel(WalletModel *model);

private:
    Ui::AskPassphraseDialog *ui;
    Mode mode;
    WalletModel *model;
    bool fCapsLock;
    SecureString* m_passphrase_out;

private Q_SLOTS:
    void textChanged();
    void secureClearPassFields();
    void toggleShowPassword(bool);

protected:
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // ZEO_QT_ASKPASSPHRASEDIALOG_H
